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


const int INF = 2000000000;
const int MAX_V = 100;

int tc, TC;
int V;

bool visited[MAX_V + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> V, V)
	{
		vector<vector<int> > adj(V+1);

		int sv;
		while (cin >> sv, sv)
		{
			int dv;

			while (cin >> dv, dv)
			{
				adj[sv].push_back(dv);
			}
		}

		int N;
		cin >> N;

		while (N--)
		{
			cin >> sv;

			memset(visited, false, sizeof visited);

			queue<int> q;

			q.push(sv);

			int cv = 0;

			while (!q.empty())
			{
				int v = q.front();
				q.pop();

				for (int u : adj[v])
				{
					if (!visited[u])
					{
						q.push(u);
						visited[u] = true;
						cv++;
					}
				}
			}

			cout << V - cv;

			for (int v = 1; v <= V; v++)
			{
				if (!visited[v])
				{
					cout << ' ' << v;
				}
			}

			cout << '\n';
		}
	}
	
	return 0;
}


