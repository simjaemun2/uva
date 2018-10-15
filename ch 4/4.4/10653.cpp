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


#define MAX_RC 1000
#define MAX_D 4

bool graph[MAX_RC + 1][MAX_RC + 1];

int DR[MAX_D] = { -1,1,0,0 };
int DC[MAX_D] = { 0,0,-1,1 };

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int R, C;

	while (cin >> R >> C, R + C)
	{
		memset(graph, false, sizeof graph);


		int RR;
		cin >> RR;
		while (RR--)
		{
			int r, nr;
			cin >> r >> nr;

			while (nr--)
			{
				int c;
				cin >> c;

				graph[r][c] = true;
			}
		}

		int sr, sc, dr, dc;

		cin >> sr >> sc >> dr >> dc;

		queue<pair<int, pair<int, int> > > q;

		q.push({ 0, {sr, sc} });
		graph[sr][sc] = true;

		while (!q.empty())
		{
			int step = q.front().first;
			int cr = q.front().second.first;
			int cc = q.front().second.second;

			q.pop();

			if (cr == dr && cc == dc)
			{
				cout << step << '\n';
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int nextR = DR[d] + cr;
				int nextC = DC[d] + cc;

				if (0 <= nextR && nextR < R && 0 <= nextC && nextC < C && !graph[nextR][nextC])
				{
					graph[nextR][nextC] = true;
					q.push({ step + 1, {nextR,  nextC} });
				}
			}
		}
	}


	return 0;
}
