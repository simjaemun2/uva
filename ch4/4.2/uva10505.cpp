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

const int INF = 987654321;
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1};
int DX[] = { 0,-1,0,1,-1,1,-1,1};

const int MAX_N = 200;
int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		vector<int> color(N + 1, INF);
		vector<vector<int> > adj(N + 1);

		for (int n = 1; n <= N; n++)
		{
			int a;
			cin >> a;
			for (int i = 0; i < a; i++)
			{
				int e;
				cin >> e;

				if (e <= N)
				{
					if (find(adj[n].begin(), adj[n].end(), e) == adj[n].end())
					{
						adj[n].push_back(e);
					}
						
					if (find(adj[e].begin(), adj[e].end(), n) == adj[e].end())
					{
						adj[e].push_back(n);
					}
				}
				
			}
		}

		
		int answer = 0;
		
		for (int i = 1; i <= N; i++)
		{
			bool isBipartite = true;

			if (color[i] == INF)
			{
				color[i] = 0;
				int cnt[2] = { 1,0 };
				queue<int> q;
				q.push(i);
				
				while (!q.empty())
				{
					int u = q.front();
					q.pop();

					for (int v : adj[u])
					{
						if (color[v] == INF)
						{
							color[v] = 1 - color[u];
							cnt[color[v]]++;
							q.push(v);
						}
						else if (color[v] == color[u])
						{
							isBipartite = false;
						}
					}
				}

				if (isBipartite)
				{
					answer += max(cnt[0], cnt[1]);
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}



