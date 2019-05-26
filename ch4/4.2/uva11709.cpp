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
int P,T;

const int VISITED = 1;
const int UNVISITED = 0;
const int LINE_LEN = 6;
const int NUM_ALP = 26;

VVI adj;
VI dfs_num, dfs_low;
vector<bool> visited, exists;
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
		VI a;
		while (true)
		{
			int v = st.back();
			st.pop_back();
			visited[v] = false;
			a.push_back(v);

			if (v == u)
			{
				break;
			}
		}

		answer++;
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	tc = 1;
	string line;

	while (cin >> P >> T, P|T)
	{
		adj = VVI(P + 1);
		
		dfs_low = VI(P + 1, UNVISITED);
		dfs_num = VI(P + 1, UNVISITED);
		visited = VB(P + 1, false);
		exists = VB(P + 1, false);
		

		st.clear();
		dfs_count = 0;
		
		VS names;
		map<string, int> nameMap;

		for (int p = 1; p <= P; p++)
		{
			string a, b;
			cin >> a >> b;
			a += b;

			names.push_back(a);
			nameMap[a] = names.size();
		}

		for (int t = 0; t < T; t++)
		{
			string a, b, c, d;
			cin >> a >> b >> c >> d;
			a += b;
			c += d;

			adj[nameMap[a]].push_back(nameMap[c]);
			//adj[nameMap[c]].push_back(nameMap[a]);
		}

		answer = 0;

		for (int n = 1; n <= P; n++)
		{
			if (dfs_num[n] == UNVISITED)
			{
				dfs(n);
			}
		}

		cout << answer << '\n';
	}

	return 0;
}



