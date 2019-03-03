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

using namespace std;

#define MAX_N 2000
#define MAX_D 4

int DR[MAX_D] = { -1,1,0,0 };
int DC[MAX_D] = { 0,0,-1,1 };

bool graph[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int p1, p2;

	
	while (cin >> p1, p1)
	{
		memset(graph, false, sizeof graph);
		memset(visited, false, sizeof visited);

		queue<pair<int, pair<int, int> > > q;

		for (int i = 0; i < p1; i++)
		{
			int a, b;
			cin >> a >> b;
			visited[a][b] = true;

			q.push({ 0, {a,b} });
		}

		cin >> p2;

		

		for (int i = 0; i < p2; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a][b] = true;
		}

		while (!q.empty())
		{
			int step = q.front().first;
			int cr = q.front().second.first;
			int cc = q.front().second.second;

			q.pop();

			if (graph[cr][cc])
			{
				cout << step << '\n';
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int nextR = DR[d] + cr;
				int nextC = DC[d] + cc;

				if (0 <= nextR && nextR <= MAX_N
					&& 0 <= nextC && nextC <= MAX_N
					&& !visited[nextR][nextC])
				{
					visited[nextR][nextC] = true;
					q.push({ step + 1, {nextR, nextC} });
				}
			}
		}
	}



	return 0;
}
