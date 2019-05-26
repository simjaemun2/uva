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
VI dfs_num, dfs_low, dfs_parent;
vector<bool > articulation_point;
int dfs_count, dfs_root, root_children;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = ++dfs_count;

	for (int v : adj[u])
	{
		if (dfs_num[v] == UNVISITED)
		{
			if (dfs_root == u)
			{
				root_children++;
			}


			dfs_parent[v] = u;

			dfs(v);
	
			if(dfs_num[u] <= dfs_low[v]) //articulation point
			{
				articulation_point[u] = true;
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (dfs_parent[u] != v) // back edge and not cycle
		{
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
	while (cin >> N, N)
	{
		if (tc != 1)
			cout << '\n';
		adj = VVI(N + 1);
		
		dfs_low = VI(N + 1, UNVISITED);
		dfs_parent = VI(N + 1, UNVISITED);
		dfs_num = VI(N + 1, UNVISITED);
		articulation_point = vector<bool>(N + 1, false);

		dfs_count = 0;

		map<string, int> cityMap;
		vector<string> v;

		for (int n = 1; n <= N; n++)
		{
			string line;
			cin >> line;
			cityMap[line] = n;
			v.push_back(line);
		}

		cin >> M;

		for (int m = 1; m <= M; m++)
		{
			string u, v;
			cin >> u >> v;
			adj[cityMap[u]].push_back(cityMap[v]);
			adj[cityMap[v]].push_back(cityMap[u]);
		}

		for (int n = 1; n <= N; n++)
		{
			if (dfs_num[n] == UNVISITED)
			{
				dfs_root = n;
				root_children = 0;
				dfs(n);

				articulation_point[n] = (root_children > 1);
			}
		}

		int cnt = 0;
		vector<string> answer;
		for (int i = 1; i <= N; i++)
		{
			if (articulation_point[i])
			{
				answer.push_back(v[i - 1]);
			}
		}

		cout << "City map #" << tc++ << ": " << answer.size() << " camera(s) found\n";

		sort(answer.begin(), answer.end());

		for (string s : answer)
		{
			cout << s << '\n';
		}
	}

	return 0;
}



