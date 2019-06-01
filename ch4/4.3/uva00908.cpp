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
	
	bool isFirst = true;

	while (cin >> N)
	{
		if (!isFirst)
			cout << '\n';
		isFirst = false;

		for (int n = 1; n <= N; n++)
		{
			parent[n] = n;
			weight[n] = 1;
		}


		vector<pair<int, pair<int, int> > > edges;

		int orgSum = 0;
		int newSum = 0;

		for (int n = 0; n < N - 1; n++)
		{
			int a, b, c;

			cin >> a >> b >> c;

			orgSum += c;
		}

		cin >> K;

		for (int k = 0; k < K; k++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ c, {a,b} });
		}

		cin >> M;

		for (int m = 0; m < M; m++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ c, {a,b} });
		}

		sort(edges.begin(), edges.end());

		for (auto edge : edges)
		{
			int c = edge.first;
			int a = edge.second.first;
			int b = edge.second.second;

			if (!isSameSet(a, b))
			{
				newSum += c;
				merge(a, b);
			}
		}

		cout << orgSum << '\n' << newSum << '\n';
	}

	return 0;
}