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
const int LINE_LEN = 6;
const int NUM_ALP = 26;

VVI adj;
VI dfs_num, dfs_low;
vector<bool> visited, exists;
int dfs_count;
VI st;
VVI answer;

bool compare(const VI& a, const VI& b)
{
	return a[0] < b[0];
}

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
		sort(a.begin(), a.end());
		answer.push_back(a);
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	tc = 1;
	string line;

	while (cin >> N, N)
	{
		if (tc != 1)
			cout << '\n';
		tc++;


		adj = VVI(NUM_ALP + 1);
		
		dfs_low = VI(NUM_ALP + 1, UNVISITED);
		dfs_num = VI(NUM_ALP + 1, UNVISITED);
		visited = vector<bool>(NUM_ALP + 1, false);
		exists = vector<bool>(NUM_ALP + 1, false);
		

		st.clear();
		dfs_count = 0;
		
		answer.clear();

		for (int n = 0; n < N; n++)
		{
			VI v;
			for (int i = 0; i < LINE_LEN; i++)
			{
				cin >> line;
				v.push_back(line[0] - 'A' + 1);
				exists[line[0] - 'A' + 1] = true;
			}

			for (int i = 0; i < LINE_LEN-1; i++)
			{
				if (v[i] != v[LINE_LEN - 1])
				{
					adj[v[LINE_LEN - 1]].push_back(v[i]);
				}
			}
		}
		
		for (int n = 1; n <= NUM_ALP; n++)
		{
			if (exists[n] && dfs_num[n] == UNVISITED)
			{
				dfs(n);
			}
		}

		sort(answer.begin(), answer.end(), compare);

		for (auto va : answer)
		{
			cout << (char)(va[0] + 'A' - 1);
			for (int i = 1; i < va.size(); i++)
			{
				cout << ' ' << (char)(va[i] + 'A' - 1);
			}
			cout << '\n';
		}

	}

	return 0;
}



