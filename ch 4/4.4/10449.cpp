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

int N, R, Q;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> N)
	{
		vector<int> boj(N + 1);
		vector<vector<pair<int, int> > > adj(N + 1);
		vector<int > dist(N + 1, INF);

		for (int n = 1; n <= N; n++)
		{
			cin >> boj[n];
		}

		cin >> R;

		for (int r = 0; r < R; r++)
		{
			int u, v;
			cin >> u >> v;

			int w = boj[v] - boj[u];

			adj[u].push_back({ v, w*w*w });
		}

		dist[1] = 0;
		

		for (int n = 0; n < N-1; n++)
		{
			for (int u = 1; u <= N; u++)
			{
				if (dist[u] != INF)
				{
					for (auto p : adj[u])
					{
						int v = p.first;
						int w = p.second;

						if (dist[v] > dist[u] + w)
							dist[v] = dist[u] + w;
					}
				}
			}
		}

		for (int u = 1; u <= N; u++)
		{
			if (dist[u] != INF)
			{
				for (auto p : adj[u])
				{
					int v = p.first;
					int w = p.second;

					if (dist[v] > dist[u] + w)
						dist[v] = -INF;
				}
			}
		}

		cin >> Q;

		cout << "Set #" << tc++ << '\n';

		while (Q--)
		{
			int q;
			cin >> q;

			if (dist[q] < 3 || dist[q] == INF)
				cout << "?\n";
			else
				cout << dist[q] << '\n';
		}
	}

	return 0;
}