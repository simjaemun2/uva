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

#define MAX_N 10000
#define INF 987654321

int N, M, S, T, P;

void dijkstra(int s, vector<vector<pair<int, int> > >& adj, vector<int>& dist)
{
	dist[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	pq.push({ 0, s });

	while (!pq.empty())
	{
		int d = pq.top().first;
		int u = pq.top().second;

		pq.pop();

		if (d > dist[u])
			continue;

		for (auto p : adj[u])
		{
			int v = p.first;
			int w = p.second;

			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;

	while (TC--)
	{
		cin >> N >> M >> S >> T >> P;

		vector<vector<pair<int, int> > > fadj(N + 1);
		vector<vector<pair<int, int> > > radj(N + 1);
		vector<int> fdist(N + 1, INF);
		vector<int> rdist(N + 1, INF);

		for (int m = 0; m < M; m++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			fadj[u].push_back({ v, c });
			radj[v].push_back({ u, c });
		}

		dijkstra(S, fadj, fdist);

		if (fdist[S] == INF || fdist[S] > P)
		{
			cout << -1 << '\n';
			continue;
		}
			
		dijkstra(T, radj, rdist);

		int maxToll = -1;

		for (int u = 1; u <= N; u++)
		{
			for (auto p : fadj[u])
			{
				int v = p.first;
				int w = p.second;

				if (fdist[u] + w + rdist[v] <= P && w > maxToll)
					maxToll = w;
			}
		}

		cout << maxToll << '\n';
	}
	

	return 0;
}