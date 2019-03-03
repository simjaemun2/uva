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

#define MAX_MN 999
#define INF 987654321
#define MAX_D 4

int N, M;

int graph[MAX_MN + 1][MAX_MN + 1];
int cost[MAX_MN + 1][MAX_MN + 1];


int DR[MAX_D] = { -1,1,0,0 };
int DC[MAX_D] = { 0,0,-1,1 };


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				cin >> graph[n][m];
				cost[n][m] = INF;
			}
		}

		priority_queue<
			pair<int, pair<int, int> >,
			vector<pair<int, pair<int, int> > >,
			greater<pair<int, pair<int, int> >>
		> pq;

		pq.push({ graph[0][0], {0,0} });
		cost[0][0] = graph[0][0];

		while (!pq.empty())
		{
			int step = pq.top().first;
			int cr = pq.top().second.first;
			int cc = pq.top().second.second;

			pq.pop();

			if (step > cost[cr][cc])
				continue;

			for (int d = 0; d < MAX_D; d++)
			{
				int nr = cr + DR[d];
				int nc = cc + DC[d];

				if (0 <= nr && nr < N
					&& 0 <= nc && nc < M
					&& cost[cr][cc] + graph[nr][nc] < cost[nr][nc])
				{
					cost[nr][nc] = cost[cr][cc] + graph[nr][nc];
					pq.push({ cost[nr][nc] , {nr,nc} });
				}
			}
		}

		cout << cost[N - 1][M - 1] << '\n';
	}



	return 0;
}
