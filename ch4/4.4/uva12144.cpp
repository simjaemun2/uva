#define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>
#include <map>
#include <limits.h>
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;
typedef pair<int, PII> PPII;
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;
typedef vector<double > VD;
typedef vector<PII> VPII;
typedef vector<vector<PII> > VVPII;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};

int N, M, S, D;

VVPII adj;
set<int> s;

int dijkstra()
{
	priority_queue<PII> pq;
	VI dist(N, INF);
	VI parent(N, -1);

	dist[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty())
	{
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (dist[u] <= d)
		{
			for (auto p : adj[u])
			{
				int v = p.second;
				int nd = d + p.first;

				if (dist[v] > nd && s.find(v) == s.end())
				{
					dist[v] = nd;
					pq.push({ -nd, v });
					parent[v] = u;
				}
			}
		}
	}

	if (dist[D] < INF)
	{
		int u = D;
		while (u != S)
		{
			s.insert(parent[u]);
			adj[u].clear();
			u = parent[u];
		}
	}

	return dist[D];
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	while (cin >> N >> M, N||M)
	{
		cin >> S >> D;

		adj = VVPII(N);
		s.clear();

		int shortest = INF;

		for (int m = 0; m < M; m++)
		{
			int u, v, d;
			cin >> u >> v >> d;

			if (u == S && v == D)
			{
				shortest = d;
			}
			else
			{
				adj[u].push_back({ d,v });
			}
		}

		if (shortest == INF)
		{
			shortest = dijkstra();
		}
		
		int second = INF;
		if (shortest < INF)
		{
			second = dijkstra();

			while (second < INF)
			{
				if (second > shortest)
				{
					break;
				}

				second = dijkstra();
			}
		}

		if (second == INF)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << second << '\n';
		}
	}
	
	

	return 0;
}