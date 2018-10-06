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

#define MAX_N 200

int N, L;

vector<vector<int> > adj;
int visited[MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		cin >> L;

		adj.clear();
		adj.resize(N);
		memset(visited, 0, sizeof visited);

		for (int i = 0; i < L; i++)
		{
			int a, b;
			cin >> a >> b;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		queue<pair<int, int>> q;
		q.push({0, 1});

		bool isBipartite = true;

		while (!q.empty())
		{
			int curNode = q.front().first;
			int curColor = q.front().second;
			q.pop();

			visited[curNode] = curColor;

			for (int nextNode : adj[curNode])
			{
				if (visited[nextNode] == 0)
					q.push({ nextNode, curColor * -1 });
				else if (visited[nextNode] == curColor)
				{
					isBipartite = false;
					break;
				}
			}
		}

		if (!isBipartite)
			cout << "NOT ";
		cout << "BICOLORABLE.\n";
	}



	return 0;
}