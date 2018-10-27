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

#define MAX_N 20000
#define INF 987654321
#define MAX_D 4

int N,S,T,M;

int cost[MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;

	for(int tc = 1; tc <= TC;tc++)
	{
		
		cin >> N >> M >> S >> T;

		for (int i = 0; i < N; i++)
			cost[i] = INF;

		vector<vector<pair<int, int> > > adj(N+1);

		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}
		

		priority_queue<
			pair<int, int >,
			vector<pair<int, int > >,
			greater<pair<int, int >>
		> pq;

		pq.push({ 0, S });
		cost[S] = 0;

		while (!pq.empty())
		{
			int step = pq.top().first;
			int u = pq.top().second;

			pq.pop();

			if (step > cost[u])
				continue;

			for (pair<int, int> p : adj[u])
			{
				int v = p.first;
				int c = p.second;

				if (cost[v] > cost[u] + c)
				{
					cost[v] = cost[u] + c;
					pq.push({ cost[v], v });
				}
			}
		}

		cout << "Case #" << tc << ": ";
			
		if (cost[T] == INF)
			cout << "unreachable\n";
		else
			cout << cost[T] << '\n';
	}



	return 0;
}
