#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>

using namespace std;

#define MAX_RC 100
#define MAX_D 4
int R, C, M, N,W;

int graph[MAX_RC + 1][MAX_RC + 1];
int cnt[MAX_RC + 1][MAX_RC + 1];
int mdy[MAX_D] = { -1,-1,1,1 };
int mdx[MAX_D] = { -1,1,-1,1 };
int visited[2];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> R >> C >> M >> N >> W;

		//cout << tc << ' ' << R << ' ' << C << ' ' << M << ' ' << N << ' ' << W << '\n';

		memset(graph, 0, sizeof graph);
		memset(cnt, 0, sizeof cnt);

		while(W--)
		{
			int x, y;
			cin >> x >> y;
			graph[x][y] = -1;
		}

		int dy[8] = {M,M,-M,-M,N,N,-N,-N};
		int dx[8] = { N,-N,N,-N,M,-M,M,-M };

		queue<pair<int, int> > q;
		graph[0][0] = 1;
		q.push({ 0,0 });

		while (!q.empty())
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			set<pair<int, int> > s;

			int c = 0;

			for (int d = 0; d < 8; d++)
			{
				int nextY = cy + dy[d];
				int nextX = cx + dx[d];

				if (0 <= nextY && nextY < C && 0 <= nextX && nextX < R)
				{
					if (graph[nextX][nextY] != -1 && s.find({ nextX, nextY }) == s.end())
					{
						s.insert({ nextX, nextY });
						c++;
					}

					if (graph[nextX][nextY] == 0)
					{
						q.push({ nextX, nextY });
						graph[nextX][nextY] = 1;
					}
				}
			}

			cnt[cx][cy] = c;
		}

		visited[0] = visited[1] = 0;

		if (cnt[0][0] == 0)
			cnt[0][0] = 2;
		
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				if(cnt[x][y])
					visited[cnt[x][y] % 2]++;
			}
		}


		cout << "Case " << tc << ": " << visited[0] << ' ' << visited[1] << '\n';
		
	}
	
	return 0;
}
