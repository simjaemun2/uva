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

#define MAX_N 100

int N,R;

int graph[MAX_N][MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++)
	{
		cout << "Case " << tc << ": ";

		cin >> N >> R;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j] = INF;
			}

			graph[i][i] = 0;
		}

		while (R--)
		{
			int u, v;
			cin >> u >> v;

			graph[u][v] = 1;
			graph[v][u] = 1;
		}

		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}

		int answer = 0;

		int S, D;
		cin >> S >> D;

		for (int i = 0; i < N; i++)
		{
			if (graph[S][i] != INF && graph[i][D] != INF)
				answer = max(answer, graph[S][i] + graph[i][D]);
		}

		cout << answer << '\n';
	}

	return 0;
}