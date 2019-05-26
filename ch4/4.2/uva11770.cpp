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

const int MAX_N = 200;
int N,M;

const int VISITED = 1;
const int UNVISITED = 0;
const int LINE_LEN = 6;
const int NUM_ALP = 26;

VVI adj;
VI dfs_num, dfs_low, dfs_parent;
vector<bool> visited, has_parent;
int dfs_count;
VI st;
int answer;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = ++dfs_count;
	visited[u] = true;
	st.push_back(u);

	for (int v : adj[u])
	{
		if (dfs_num[v] == UNVISITED)
		{
			dfs(v);
		}

		if (visited[v] == true)
		{
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

	if (dfs_low[u] == dfs_num[u])
	{
		while (true)
		{
			int v = st.back();
			st.pop_back();
			visited[v] = false;
			dfs_parent[v] = u;

			if (v == u)
			{
				break;
			}
		}

		//answer++;
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> TC;

	for(tc=1;tc<=TC;tc++)
	{
		cin >> N >> M;
		adj = VVI(N + 1);
		
		dfs_low = VI(N + 1, UNVISITED);
		dfs_num = VI(N + 1, UNVISITED);
		dfs_parent = VI(N + 1, UNVISITED);
		visited = VB(N + 1, false);
		has_parent = VB(N + 1, false);
		st.clear();
		dfs_count = 0;
	
		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		for (int n = 1; n <= N; n++)
		{
			if (dfs_num[n] == UNVISITED)
			{
				dfs(n);
			}
		}

		for (int u = 1; u <= N; u++)
		{
			has_parent[dfs_parent[u]] = true;
		}

		for (int u = 1; u <= N; u++)
		{
			for (int v : adj[u])
			{
				if (dfs_parent[u] != dfs_parent[v])
				{
					has_parent[dfs_parent[v]] = false;
				}
			}
		}

		int answer = 0;

		for (int u = 1; u <= N; u++)
		{
			answer += has_parent[u];
		}

		cout << "Case " << tc << ": " << answer << '\n';
	}

	return 0;
}



