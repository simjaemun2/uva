#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>

using namespace std;

#define MAX_N 10000
#define UNVISITED -1

int N,M;

vector<vector<int> > adj;
vector<pair<int, int> > answer;
int dfs_num[MAX_N + 1];
int dfs_low[MAX_N + 1];
int dfs_parent[MAX_N + 1];
int dfsNumberCounter;
int dfsRoot;
int rootChildren;


bool articulation_vertex[MAX_N + 1];

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

void articulationPointAndBridge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for (int v : adj[u])
	{
		if (dfs_num[v] == UNVISITED) // unvisited
		{
			dfs_parent[v] = u;

			if (u == dfsRoot)
				rootChildren++;

			articulationPointAndBridge(v);

			if (dfs_low[v] >= dfs_num[u])
			{
				articulation_vertex[u] = true;
				answer[u].first++;
			}
				

			//if(dfs_low[v] > dfs_num[u])

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);

		//if()
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> M, N + M)
	{
		adj.clear();
		adj.resize(N);

		answer.clear();
		
		for (int i = 0; i < N; i++)
		{
			answer.push_back({ 0, i });
		}
		
		memset(dfs_num, UNVISITED, sizeof dfs_num);
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_parent, UNVISITED, sizeof dfs_parent);
		memset(articulation_vertex, false, sizeof articulation_vertex);

		int a, b;
		while (cin >> a >> b, a + b != -2)
		{
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfsNumberCounter = 0;
		
		

		for (int i = 0; i < N; i++)
		{
			if (dfs_num[i] == UNVISITED)//unvisited
			{
				dfs_parent[i] = i;
				dfsRoot = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
				answer[i].first = rootChildren;
			}
		}
		
		
		answer[0].first--;

		sort(answer.begin(), answer.end(), cmp);

		for (int i = 0; i < M; i++)
		{
			cout << answer[i].second << ' ' << answer[i].first + 1 << '\n';
		}

		cout << '\n';
		
	}


	return 0;
}