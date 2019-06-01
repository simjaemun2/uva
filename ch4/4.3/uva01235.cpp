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

int getRolls(string a, string b)
{
	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int d = abs(a[i] - b[i]);
		sum += d > 5 ? 10 - d : d;
	}

	return sum;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		/*
		if (tc != 1)
			cout << '\n';
		*/
		cin >> N;

		for (int n = 1; n <= N; n++)
		{
			parent[n] = n;
			weight[n] = 1;
		}

		vector<pair<int, pair<int, int> > > edges;
		vector<string> vertices(N + 1);

		int sum = 9999;

		for (int i = 1; i <= N; i++)
		{
			cin >> vertices[i];

			for (int j = 1; j < i; j++)
			{
				int d = getRolls(vertices[i], vertices[j]);
				edges.push_back({ d, {i, j} });
			}

			sum = min(sum, getRolls(vertices[i], "0000"));
		}


		sort(edges.begin(), edges.end());

		//cout << "Case " << tc << ":\n";

		for (auto edge : edges)
		{
			int c = edge.first;
			int a = edge.second.first;
			int b = edge.second.second;

			if (!isSameSet(a, b))
			{
				merge(a, b);

				sum += c;
			}
		}

		cout << sum << '\n';
	}

	return 0;
}