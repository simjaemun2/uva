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

#define MAX_N 100

int N;

vector<vector<int> > adj;
vector<pair<int, int> > bridges;
int dfs_num[MAX_N + 1];
int dfs_low[MAX_N + 1];
int dfs_parent[MAX_N + 1];
int dfsNumberCounter;
int dfsRoot;
int rootChildren;


bool articulation_vertex[MAX_N + 1];

void articulationPointAndBridge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for (int v : adj[u])
	{
		if (!dfs_num[v]) // unvisited
		{
			dfs_parent[v] = u;

			if (u == dfsRoot)
				rootChildren++;

			articulationPointAndBridge(v);

			if (dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;

			if (dfs_low[v] > dfs_num[u])
			{
				if (v > u)
					bridges.push_back({ u, v });
				else
					bridges.push_back({ v, u });
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		adj.clear();
		adj.resize(N);
		bridges.clear();

		memset(dfs_num, 0, sizeof dfs_num);
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_parent, 0, sizeof dfs_parent);
		memset(articulation_vertex, false, sizeof articulation_vertex);

		string b;
		int a, c;

		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			
			int edgeNum = stoi(b.substr(1, b.size() - 2));

			for (int j = 0; j < edgeNum; j++)
			{
				cin >> c;
				adj[a].push_back(c);
			}

		}



		dfsNumberCounter = 1;


		for (int i = 1; i < N; i++)
		{
			if (!dfs_num[i])//unvisited
			{
				dfsRoot = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}

		/*
		int answer = 0;

		for (int i = 1; i <= N; i++)
			if (articulation_vertex[i])
				answer++;
		*/


		cout << bridges.size() << " critical links" << '\n';

		sort(bridges.begin(), bridges.end());

		for (auto p : bridges)
			cout << p.first << " - " << p.second << '\n';
		cout << '\n';

	}


	return 0;
}