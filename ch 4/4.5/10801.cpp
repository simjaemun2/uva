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

#define MAX_T 100
#define MAX_FLOOR 100
#define INF 987654321
#define MAX_N 5

int N,K;

int T[MAX_T + 1];
int cost[MAX_FLOOR + 1];



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while(cin >> N >> K)
	{
		vector<vector<pair<int, int> > > adj(100);


		for (int n = 0; n < N; n++)
			cin >> T[n];
		
		
		for (int i = 0; i < MAX_FLOOR; i++)
			cost[i] = INF;
		
		//memset(cost, -1, sizeof cost);
		

		cin.ignore();

		for (int n = 0; n < N; n++)
		{
			string line;
			getline(cin, line);

			istringstream iss(line);

			vector<int> v;
			int a;
			while (iss >> a)
			{
				for (int to : v)
				{
					adj[a].push_back({ to, (a - to) * T[n] });
					adj[to].push_back({ a, (a - to) * T[n] });
				}

				v.push_back(a);
			}
		}
		

		priority_queue<
			pair<int, int >,
			vector<pair<int, int > >,
			greater<pair<int, int >>
		> pq;

		pq.push({ 0, 0 });
				
		cost[0] = 0;

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
				int candiCost = cost[u] + c + 60;


				if (cost[v] > candiCost)
				{
					cost[v] = candiCost;
					pq.push({ cost[v], v});
				}
			}
			
		}
			
		if (cost[K] == INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << cost[K] - (K == 0 ? 0 : 60) << '\n';
	}



	return 0;
}
