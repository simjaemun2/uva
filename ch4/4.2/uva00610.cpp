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


const int INF = 987654321;
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1 };
int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 200;
int N, M;

const int VISITED = 1;
const int UNVISITED = 0;


VVI adj;
VPII answer;
VI dfs_num, dfs_low, dfs_parent;

int dfs_count;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = ++dfs_count;

	for (int v : adj[u])
	{
		if (dfs_num[v] == UNVISITED)
		{
			answer.push_back({ u,v });

			dfs_parent[v] = u;

			dfs(v);
	
			if(dfs_num[u] < dfs_low[v]) //not bridge
			{
				answer.push_back({ v,u });
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (dfs_parent[u] != v) // back edge and not cycle
		{
			if (dfs_num[u] > dfs_num[v])
			{
				answer.push_back({ u,v });
			}

			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	tc = 1;
	while (cin >> N >> M, N | M)
	{
		cout << tc++ << "\n\n";

		adj = VVI(N+1);
		
		dfs_low = VI(N + 1, UNVISITED);
		dfs_parent = VI(N + 1, UNVISITED);
		dfs_num = VI(N + 1, UNVISITED);

		dfs_count = 0;
		answer.clear();

		for (int m = 1; m <= M; m++)
		{
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int n = 1; n <= N; n++)
		{
			if (dfs_num[n] == UNVISITED)
			{
				dfs(n);
			}
		}

		sort(answer.begin(), answer.end());

		for (auto p : answer)
		{
			cout << p.first << ' ' << p.second << '\n';
		}

		cout << "#\n";
	}

	return 0;
}



