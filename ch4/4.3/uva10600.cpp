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

int N,M;



//vector<pair<double, double> > Vertices;
vector<pair<int, pair<int, int> > > EdgeList;
vector<pair<int, pair<int, int> > > s1EdgeList;

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


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;

	while(T--)
	{
		cin >> N >> M;
		EdgeList.clear();
		s1EdgeList.clear();

		UnionFind UF1(N + 1);

		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			EdgeList.push_back({ c, {a,b} });
		}

		sort(EdgeList.begin(), EdgeList.end());

		int s1 = 0, s2 = 987654321;

		for (auto e : EdgeList)
		{
			int d = e.first;
			int u = e.second.first;
			int v = e.second.second;

			if (!UF1.isSameSet(u, v))
			{
				UF1.unionSet(u, v);
				s1EdgeList.push_back(e);
				s1 += d;
			}
		}

		for (auto s1Edge : s1EdgeList)
		{
			UnionFind UF2(N + 1);

			int result = 0;
			int cnt = 0;

			for (auto e : EdgeList)
			{
				if (e != s1Edge)
				{
					int d = e.first;
					int u = e.second.first;
					int v = e.second.second;

					if (!UF2.isSameSet(u, v))
					{
						UF2.unionSet(u, v);
						result += d;
						cnt++;
					}
				}
			}
			if(cnt == N-1)
				s2 = min(result, s2);
		}
		

		cout << s1 << ' ' << s2 << '\n';
	}


	return 0;
}