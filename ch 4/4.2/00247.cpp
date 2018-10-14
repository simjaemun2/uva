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

map<string, int > name2index;
map<int, string> index2name;

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

			cout << index2name[v];

			visited[v] = false;

			dfs_parent[v] = u;

			if (u == v)
			{
				cout << '\n';
				break;
			}
			else
			{
				cout << ", ";
			}
		}	
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while(cin >> N >> M, N+M)
	{
		adj.clear();
		adj.resize(N+1);
		S.clear();

		answer.clear();

		memset(dfs_num, UNVISITED, sizeof dfs_num);
		memset(dfs_low, UNVISITED, sizeof dfs_low);
		memset(dfs_parent, UNVISITED, sizeof dfs_parent);

		memset(visited, false, sizeof visited);
		memset(hasParent, false, sizeof hasParent);

		index2name.clear();
		name2index.clear();

		int index = 1;

		for (int i = 1; i <= M; i++)
		{
			string a, b;
			int ia, ib;

			cin >> a >> b;

			

			if (name2index[a] == 0)
			{
				name2index[a] = index;
				index2name[index++] = a;
			
			}

			if (name2index[b] == 0)
			{
				name2index[b] = index;
				index2name[index++] = b;
			}
			

			ia = name2index[a];
			ib = name2index[b];

			adj[ia].push_back(ib);
		}
		

		cout << "Calling circles for data set " << tc++ << ":\n";

		dfsNumberCounter = 1;

		for (int i = 1; i < index; i++)
		{
			if (dfs_num[i] == UNVISITED)
			{
				tarjanSCC(i);
			}
		}
	}


	return 0;
}
