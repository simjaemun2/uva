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
int N, M,K;

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

	for (tc=1;tc<=TC;tc++)
	{
		if (tc != 1)
			cout << '\n';

		cin >> N >> M;


		for (int n = 1; n <= N; n++)
		{
			parent[n] = n;
			weight[n] = 1;
		}

		map<string, int> cityMap;

		vector<pair<int, pair<int, int> > > edges;
		int sum = 0;
		
		for (int m = 0; m < M; m++)
		{
			string a, b;
			int d, ia, ib;
			cin >> a >> b >> d;

			if (cityMap.find(a) == cityMap.end())
			{
				ia = cityMap.size() + 1;
				cityMap[a] = ia;
			}
			else
			{
				ia = cityMap[a];
			}

			if (cityMap.find(b) == cityMap.end())
			{
				ib = cityMap.size() + 1;
				cityMap[b] = ib;
			}
			else
			{
				ib = cityMap[b];
			}

			edges.push_back({ d, {ia,ib} });
		}

		sort(edges.begin(), edges.end());

		for (auto edge : edges)
		{
			int c = edge.first;
			int a = edge.second.first;
			int b = edge.second.second;

			if (!isSameSet(a, b))
			{
				sum += c;
				merge(a, b);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}