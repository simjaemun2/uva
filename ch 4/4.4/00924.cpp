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




int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int E;
	cin >> E;

	vector<vector<int> > adj(E);

	for (int i = 0; i < E; i++)
	{
		int N;
		cin >> N;

		while(N--)
		{
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
	}

	int T;
	cin >> T;

	while (T--)
	{
		int src;
		cin >> src;

		if (adj[src].size() == 0)
		{
			cout << 0 << '\n';
			continue;
		}
			

		map<int, bool> visited;
		queue<pair<int, int> > q;
		vector<int> boom(E + 1, 0);

		q.push({ src, 0 });
		visited[src] = true;

		while (!q.empty())
		{
			int node = q.front().first;
			int day = q.front().second;

			q.pop();

			boom[day]++;

			for (int nextNode : adj[node])
			{
				if (!visited[nextNode])
				{
					visited[nextNode] = true;
					q.push({ nextNode, day + 1 });
				}
			}
		}

		int ms = 0;
		int fbd = 0;

		for (int i = 1; i <= E; i++)
		{
			if (boom[i] > ms)
			{
				ms = boom[i];
				fbd = i;
			}
		}

		cout << ms << ' ' << fbd << '\n';
	}


	return 0;
}
