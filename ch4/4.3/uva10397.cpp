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
int N, M, A;

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
	
	//cin >> TC;
	//for(tc=1;tc<=TC;tc++)
	
	//while(cin >> N >> M, N|M)
	while (cin >> N)
	{
		/*
		if (tc != 1)
			cout << '\n';
		*/
		

		vector<PDD> vertices(N+1);
		vector<pair<double, pair<int, int> > > edges;
		
		for (int n = 1; n <= N; n++)
		{
			cin >> vertices[n].first >> vertices[n].second;

			for (int i = 1; i < n; i++)
			{
				double dx = vertices[n].first - vertices[i].first;
				double dy = vertices[n].second - vertices[i].second;
				
				edges.push_back({ hypotf(dx, dy), {n,i} });
			}

			parent[n] = n;
			weight[n] = 1;
		}

		cin >> M;

		for (int m = 0; m < M; m++)
		{
			int a, b;
			cin >> a >> b;
			merge(a, b);
		}
		
		sort(edges.begin(), edges.end());

		double sum = 0.0;

		for (auto edge : edges)
		{
			double d = edge.first;
			int a = edge.second.first;
			int b = edge.second.second;

			if (!isSameSet(a, b))
			{
				sum += d;
				merge(a, b);
			}
		}

		printf("%.2f\n", sum);
	}

	return 0;
}