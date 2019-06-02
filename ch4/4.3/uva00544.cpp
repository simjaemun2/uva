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
int N, M;

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
	tc = 1;

	while(cin >> N >> M, N | M)
	{
		//vector<pair<double, double> > v(N);
		vector<pair<int, pair<int, int> > > edges;
		map<string, int> cityMap;

		for (int n = 0; n < N; n++)
		{			
			parent[n] = n;
			weight[n] = 1;
		}

		string a, b;
		int d, ia, ib;

		for (int m = 0; m < M; m++)
		{
			cin >> a >> b >> d;

			if (cityMap.find(a) == cityMap.end())
			{
				ia = cityMap.size();
				cityMap[a] = ia;
			}
			else
			{
				ia = cityMap[a];
			}

			if (cityMap.find(b) == cityMap.end())
			{
				ib = cityMap.size();
				cityMap[b] = ib;
			}
			else
			{
				ib = cityMap[b];
			}

			edges.push_back({ -d, {ia, ib} });
		}

		cin >> a >> b;
		ia = cityMap[a];
		ib = cityMap[b];

		sort(edges.begin(), edges.end());

		int answer;

		for (auto p : edges)
		{
			int d = p.first;
			int u = p.second.first;
			int v = p.second.second;

			if (!isSameSet(u, v))
			{
				answer = d;
				merge(u, v);
			}

			if (isSameSet(ia, ib))
				break;
		}

		printf("Scenario #%d\n%d tons\n\n", tc++, -answer);
	}

	return 0;
}