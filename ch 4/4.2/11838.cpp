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

#define MAX_N 2000
#define UNVISITED -1

int N,M;

vector<vector<int> > adj;

vector<int> S;

vector<int> answer;

int dfs_num[MAX_N + 1];
int dfs_low[MAX_N + 1];

int dfsNumberCounter;


bool vi[MAX_N + 1];

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
		answer.push_back(u);

		while (true)
		{
			int v = S.back();
			S.pop_back();

			visited[v] = false;

			//cout << v

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

	while (cin >> N >> M, N + M)
	{
		adj.clear();
		adj.resize(N+1);
		S.clear();

		answer.clear();

		memset(dfs_num, UNVISITED, sizeof dfs_num);
		memset(dfs_low, 0, sizeof dfs_low);

		memset(visited, false, sizeof visited);

		
		for (int i = 0; i < M; i++)
		{
			int V, W, P;
			cin >> V >> W >> P;

			adj[V].push_back(W);

			if (P == 2)
				adj[W].push_back(V);
		}


		dfsNumberCounter = 0;

		for (int i = 1; i <= N; i++)
		{
			if (dfs_num[i] == UNVISITED)
			{
				tarjanSCC(i);
			}
		}

		if (answer.size() > 1)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';

		
	}


	return 0;
}