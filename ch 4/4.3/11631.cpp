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

vector<pair<double, double> > Vertices;
vector<pair<double, pair<int, int> > > EdgeList;

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

	while(cin >> M >> N, N+N)
	{
		EdgeList.clear();
		
		UnionFind UF(M);

		double sum = 0.0;

		for (int i = 0; i < N; i++)
		{
			double x, y, z;
			cin >> x >> y >> z;

			EdgeList.push_back({ z, {x,y} });

			sum += z;
		}

		sort(EdgeList.begin(), EdgeList.end());

		double minCost = 0.0;

		for (auto e : EdgeList)
		{
			double d = e.first;
			int u = e.second.first;
			int v = e.second.second;

			if (!UF.isSameSet(u, v))
			{
				UF.unionSet(u, v);
				minCost += d;

				UF.unionSet(u, v);
			}
		}

		cout << (int)(sum - minCost) << '\n';
	}


	return 0;
}