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

int N, M;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;
	while (TC--)
	{
		cin >> N >> M;

		vector<int> dist(N, INF);
		vector<vector<pair<int, int> > > adj(N);

		for (int m = 0; m < M; m++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ v, w });
		}


		for (int n = 0; n < N - 1; n++)
		{
			for (int u = 0; u < N; u++)
			{
				for (auto p : adj[u])
				{
					int v = p.first;
					int w = p.second;

					dist[v] = min(dist[v], dist[u] + w);
				}
			}
		}

		bool hasNegativeCycle = false;

		for (int u = 0; u < N && !hasNegativeCycle; u++)
		{
			for (auto p : adj[u])
			{
				int v = p.first;
				int w = p.second;

				if (dist[v] > dist[u] + w)
					hasNegativeCycle = true;
			}
		}

		if (!hasNegativeCycle)
			cout << "not possible\n";
		else
			cout << "possible\n";
	}
	

	return 0;
}