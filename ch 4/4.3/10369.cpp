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

int S, P;

typedef long long int LL;

vector<pair<double, double> > Vertices;
vector<pair<double, pair<int, int> > > EdgeList;
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

	int T;
	cin >> T;

	while(T--)
	{
		cin >> S >> P;
		EdgeList.clear();
		Vertices.clear();

		UnionFind UF(P+1);

		for (int i = 0; i < P; i++)
		{
			double x,y;
			cin >> x >> y;

			Vertices.push_back({ x,y });

			for (int j = 0; j < i; j++)
			{
				EdgeList.push_back({ getDist(i,j),{ i,j } });
			}
		}

		sort(EdgeList.begin(), EdgeList.end());

		double minCost = 0.0;
		int num_mst = 0;

		for (auto e : EdgeList)
		{
			double d = e.first;
			int u = e.second.first;
			int v = e.second.second;

			if (!UF.isSameSet(u, v))
			{
				UF.unionSet(u, v);
				minCost = d;
				num_mst++;
				if (num_mst == P-S)
					break;
			}
		}

		printf("%.2lf\n", round(minCost * 100) / 100);

			
	}


	return 0;
}