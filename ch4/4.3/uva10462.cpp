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

const int MAX_N = 100;
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
	
	cin >> TC;
	for(tc=1;tc<=TC;tc++)
	
	//while(cin >> N >> M, N|M)
	//while (cin >> N)
	{
		/*
		if (tc != 1)
			cout << '\n';
		*/
		
		cin >> N >> M;

		vector<pair<int, pair<int, PII> > > edges;

		for (int n = 1; n <= N; n++)
		{
			parent[n] = n;
			weight[n] = 1;
		}

		for (int m = 0; m < M; m++)
		{
			int a, b, d;
			cin >> a >> b >> d;

			if (b > a)
			{
				int t = a;
				a = b;
				b = t;
			}

			if (a != b)
			{
				edges.push_back({ d, {m, {a,b}} });
			}
		}

		cout << "Case #" << tc << " : ";

		sort(edges.begin(), edges.end());

		vector<pair<int, pair<int, PII> > > mstEdges;

		for (auto edge : edges)
		{
			int d = edge.first;
			int m = edge.second.first;
			int a = edge.second.second.first;
			int b = edge.second.second.second;

			if (!isSameSet(a, b))
			{
				mstEdges.push_back(edge);
				merge(a, b);
			}
		}

		set<int> parentSet;
			
		for (int n = 1; n <= N; n++)
		{
			parentSet.insert(findParent(n));
		}

		if (parentSet.size() != 1)
		{
			cout << "No way\n";
			continue;
		}

		int secondMin = INF;

		for (auto mstEdge : mstEdges)
		{
			for (int n = 1; n <= N; n++)
			{
				parent[n] = n;
				weight[n] = 1;
			}

			int sum = 0;

			for (auto edge : edges)
			{
				int d = edge.first;
				int m = edge.second.first;
				int a = edge.second.second.first;
				int b = edge.second.second.second;

				if (!isSameSet(a, b) && edge != mstEdge)
				{
					sum += d;
					merge(a, b);
				}
			}

			parentSet.clear();
				
			for (int n = 1; n <= N; n++)
			{
				parentSet.insert(findParent(n));
			}

			if (parentSet.size() == 1)
			{
				secondMin = min(secondMin, sum);
			}
		}

		if (secondMin == INF)
		{
			cout << "No second way\n";
		}
		else
		{
			cout << secondMin << '\n';
		}
	}

	return 0;
}