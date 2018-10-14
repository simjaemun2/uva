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

#define MAX_N 100000
#define UNVISITED -1

int N,M;

vector<vector<int> > adj;

vector<int > S;

vector<int > answer;

int dfs_num[MAX_N + 1];
int dfs_low[MAX_N + 1];
int dfs_parent[MAX_N + 1];

int dfsNumberCounter;


bool hasParent[MAX_N + 1];

bool visited[MAX_N + 1];

void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	S.push_back(u);

	visited[u] = true;

	for (int v : adj[u])
	{
		if (dfs_num[v] == UNVISITED)
			tarjanSCC(v);

		if (visited[v])
			dfs_low [u]= min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u])
	{
		while (S.size())
		{
			int v = S.back();
			S.pop_back();

			visited[v] = false;

			dfs_parent[v] = u;

			if (u == v)
				break;
		}	
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;

	while(T--)
	{
		cin >> N >> M;

		adj.clear();
		adj.resize(N+1);
		S.clear();

		answer.clear();

		memset(dfs_num, UNVISITED, sizeof dfs_num);
		memset(dfs_low, UNVISITED, sizeof dfs_low);
		memset(dfs_parent, UNVISITED, sizeof dfs_parent);

		memset(visited, false, sizeof visited);
		memset(hasParent, false, sizeof hasParent);

		
		for (int i = 0; i < M; i++)
		{
			int V, W;
			cin >> V >> W;

			adj[V].push_back(W);
		}

		dfsNumberCounter = 1;

		for (int i = 1; i <= N; i++)
		{
			if (dfs_num[i] == UNVISITED)
			{
				tarjanSCC(i);
			}
		}

		for (int u = 1; u <= N; u++)
		{
			hasParent[dfs_parent[u]] = true;
		}

		for (int u = 1; u <= N; u++)
		{
			for (int v : adj[u])
			{
				if (dfs_parent[u] != dfs_parent[v])
				{
					hasParent[dfs_parent[v]] = false;
				}
					
			}
		}

		int answer = 0;

		for (int u = 1; u <= N; u++)
		{
			answer += hasParent[u];
		}

		cout << answer << '\n';
	}


	return 0;
}
