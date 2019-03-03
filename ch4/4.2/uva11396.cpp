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

#define MAX_N 300

int V, E;


int visited[MAX_N+1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> V, V)
	{
		vector<vector<int> > adj(V+1);
		memset(visited, -1, sizeof visited);

		int a, b;
		
		while (cin >> a >> b, a || b)
		{
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		queue<int> q;
		visited[1] = 1;
		q.push(1);

		bool isBipartite = true;

		while (!q.empty() && isBipartite)
		{
			int curNode = q.front();
			q.pop();
			int curColor = visited[curNode];

			for (int nextNode : adj[curNode])
			{
				if (visited[nextNode] == -1)
				{
					visited[nextNode] = 1 - curColor;
					q.push(nextNode);
				}
				else if (visited[nextNode] == curColor)
				{
					isBipartite = false;
					break;
				}
			}
		}

		if (isBipartite)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}


	return 0;
}