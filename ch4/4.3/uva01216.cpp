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
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;

const int INF = 987654321;
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1 };
int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 1000000;
int N, M, K;

int parent[MAX_N + 1];
int weight[MAX_N + 1];

int findParent(int u)
{
	if (parent[u] != u)
		u = findParent(parent[u]);
	return u;
}

bool isSameSet(int u, int v)
{
	int pu = findParent(u);
	int pv = findParent(v);

	return pu == pv;
}

void merge(int u, int v)
{
	if (!isSameSet(u, v))
	{
		int pu = findParent(u);
		int pv = findParent(v);
		int wu = weight[pu];
		int wv = weight[pv];

		if (wu > wv)
		{
			parent[pv] = pu;
		}
		else
		{
			parent[pu] = pv;

			if (wu == wv)
			{
				weight[pv]++;
			}
		}

	}
}


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	
	for (tc = 1; tc <= TC; tc++)
	{
		vector<pair<double, double> > vertices;
		vector<pair<double, pair<int, int> > > edges;

		cin >> K;

		int u, v;
		while (cin >> u, u != -1)
		{
			cin >> v;

			vertices.push_back({ u,v });
		}

		for (int n = 0; n < vertices.size(); n++)
		{
			parent[n] = n;
			weight[n] = 1;

			for (int i = 0; i < n; i++)
			{
				edges.push_back({ hypot(vertices[n].first - vertices[i].first,vertices[n].second - vertices[i].second)
					, {n, i} });
			}
		}

		sort(edges.begin(), edges.end());

		double answer;

		for (auto p : edges)
		{
			int u = p.second.first;
			int v = p.second.second;

			if (!isSameSet(u, v))
			{
				answer = p.first;
				merge(u, v);
			}

			set<int> s;

			for (int i = 0; i < vertices.size(); i++)
			{
				s.insert(findParent(i));
			}

			if (s.size() == K)
			{
				break;
			}
		}

		printf("%.0f\n", ceil(answer));
	}
	
	return 0;
}