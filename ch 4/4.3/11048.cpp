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

using namespace std;

#define MAX_Q 10000
#define MAX_C 100

int C, S, Q;

typedef long long int LL;

vector<vector<pair<int, int> > > adj;
vector<pair<int, pair<int, int> > > EdgeList;
bool visited[MAX_C + 1];

class UnionFind{
private: vector<int > p, rank;

public:
	UnionFind(int N)
	{
		rank.assign(N, 0);
		p.resize(N);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}

	int findSet(int i)
	{
		return p[i] == i ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x = findSet(i);
			int y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};
/*
double getDist(int u, int v)
{
	double dx = Vertices[u].first - Vertices[v].first;
	double dy = Vertices[u].second - Vertices[v].second;
	return sqrt(dx*dx + dy*dy);
}
*/

void dfs(int u, int v, int maxDist)
{
	if (u == v)
	{
		cout << maxDist << '\n';
		return;
	}

	for (auto nextV : adj[u])
	{
		int d = nextV.second;
		if (!visited[nextV.first])
		{
			visited[nextV.first] = true;
			dfs(nextV.first, v, max(maxDist, nextV.second));
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while(cin >> C >> S >> Q, C+S+Q)
	{
		if (tc > 1)
			cout << '\n';
		EdgeList.clear();
		adj.clear();

		adj.resize(C + 1);

		UnionFind UF(C+1);

		for (int i = 0; i < S; i++)
		{
			int u, v;
			int w;
			cin >> u >> v >> w;

			EdgeList.push_back({ w, {u,v} });
		}

		sort(EdgeList.begin(), EdgeList.end());

		double minCost = 0.0;

		for (auto e : EdgeList)
		{
			int d = e.first;
			int u = e.second.first;
			int v = e.second.second;

			if (!UF.isSameSet(u, v))
			{
				UF.unionSet(u, v);
				adj[u].push_back({ v, d });
				adj[v].push_back({ u, d });
			}
		}

		cout << "Case #" << tc++ << '\n';

		while (Q--)
		{
			int u, v;
			cin >> u >> v;

			if (UF.isSameSet(u, v))
			{
				memset(visited, false, sizeof visited);
				visited[u] = true;
				dfs(u, v, -1);
			}
			else
			{
				cout << "no path\n";
			}
		}		
	}


	return 0;
}