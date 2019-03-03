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


int M,N;

typedef long long int LL;

vector<pair<int, int> > Vertices;
vector<pair<int, pair<int, int> > > EdgeList;

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

double getDist(int u, int v)
{
	double dx = Vertices[u].first - Vertices[v].first;
	double dy = Vertices[u].second - Vertices[v].second;
	return sqrt(dx*dx + dy*dy);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while(cin >> N >> M, N+N)
	{
		EdgeList.clear();
		
		UnionFind UF(N);

		for (int i = 0; i < M; i++)
		{
			int u, v;
			int w;
			cin >> u >> v >> w;

			EdgeList.push_back({ w, {u,v} });
		}

		sort(EdgeList.begin(), EdgeList.end());

		double minCost = 0.0;

		vector<int > cycles;

		for (auto e : EdgeList)
		{
			int d = e.first;
			int u = e.second.first;
			int v = e.second.second;

			if (!UF.isSameSet(u, v))
			{
				UF.unionSet(u, v);
			}
			else
			{
				cycles.push_back(d);
			}
		}


		if (cycles.size())
		{
			cout << cycles[0];

			for (int i = 1; i < cycles.size(); i++)
				cout << ' ' << cycles[i];
			cout << '\n';
		}
		else
		{
			cout << "forest\n";
		}
	}


	return 0;
}