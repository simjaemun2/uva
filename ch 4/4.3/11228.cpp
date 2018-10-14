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


int N;
double R;

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
				if (rank[x] = rank[y])
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

	for (int tc = 1; tc <= T; tc++)
	{
		cout << "Case #" << tc << ": ";

		cin >> N >> R;

		Vertices.clear();
		EdgeList.clear();
		
		UnionFind UF(N);

		for (int i = 0; i < N; i++)
		{
			double x, y;
			cin >> x >> y;
			Vertices.push_back({ x, y });

			for (int j = 0; j < i; j++)
			{
				EdgeList.push_back({ getDist(i,j), {i,j} });
			}
		}

		sort(EdgeList.begin(), EdgeList.end());

		double roads = 0.0;
		double railroads = 0.0;
		int states = 1;

		for (auto e : EdgeList)
		{
			double d = e.first;
			int u = e.second.first;
			int v = e.second.second;

			if (!UF.isSameSet(u, v))
			{
				UF.unionSet(u, v);
				if (d > R)
				{
					states++;
					railroads += d;
				}
				else
				{
					roads += d;
				}
			}
		}

		cout << states << ' ' << (int)round(roads) << ' ' << (int)round(railroads) << '\n';
		
	}


	return 0;
}