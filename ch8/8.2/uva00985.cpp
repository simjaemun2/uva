#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>
#include <math.h>
#include <functional>

using namespace std;

#define INF 987654321

#define MAX_I 60
#define MAX_R 3600

typedef long long int LL;

#define MAX_RC 500
#define MAX_D 4

int R, C;


int graph[MAX_RC][MAX_RC];
int possibleDir[MAX_RC][MAX_RC];

struct Node {
	int r, c, step;
};

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> R >> C)
	{
		memset(graph, 0, sizeof graph);
		memset(possibleDir, 0, sizeof possibleDir);

		map<char, int> m;
		m['N'] = 0;
		m['E'] = 1;
		m['S'] = 2;
		m['W'] = 3;

		/*
		//        N   E  S  W
int DR[MAX_D] = { -1, 0, 1, 0 };
int DC[MAX_D] = { 0, 1, 0, -1 };
		
		*/
		map<int, pair<int, int> > D;
		D[1 << 0] = {-1,0};
		D[1 << 1] = { 0,1 };
		D[1 << 2] = { 1,0 };
		D[1 << 3] = { 0,-1 };

		for (int i = 0; i < R*C - 1; i++)
		{
			string line;
			cin >> line;

			for (char c : line)
				possibleDir[i/C][i%C] |= 1 << m[c];
		}

		Node n;
		n.r = n.c = n.step = 0;
		graph[0][0] = 1;

		queue<Node > q;

		q.push(n);

		int answer = -1;

		while (!q.empty())
		{
			Node node = q.front();
			q.pop();

			if (node.r == R - 1 && node.c == C - 1)
			{
				answer = node.step;
				break;
			}

			int cd = node.step % MAX_D;

			for (int i = 0; i < MAX_D; i++)
			{
				if (possibleDir[node.r][node.c] & (1 << i))
				{
					int nD = (i + cd) % MAX_D;
					int nDir = 1 << nD;
					int nextR = node.r + D[nDir].first;
					int nextC = node.c + D[nDir].second;

					if (0 <= nextR && nextR < R
						&& 0 <= nextC && nextC < C
						&& !(graph[nextR][nextC] & (1 << (cd + 1))))
					{
						Node nextNode;
						nextNode.r = nextR;
						nextNode.c = nextC;
						nextNode.step = node.step + 1;
						q.push(nextNode);
						graph[nextR][nextC] |= (1 << (cd + 1));
					}
				}
			}
		}

		if (answer == -1)
			cout << "no path to exit\n";
		else
			cout << answer << '\n';
	}
	
	return 0;
}