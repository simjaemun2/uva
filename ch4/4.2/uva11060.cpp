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
#define MAX_D 4

int N, M;


vector<string> items;
map<string, vector<string> > adj;
map<string, int> indegrees;
map<string, bool> visited;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int tc = 1;

	while (cin >> N)
	{

		items.clear();
		adj.clear();
		indegrees.clear();
		visited.clear();

		string a,b;

		for (int i = 0; i < N; i++)
		{
			cin >> a;
			items.push_back(a);
		}

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			indegrees[b]++;
		}

		queue<string> q;
		
		for (string item : items)
		{
			if (indegrees[item] == 0)
			{
				q.push(item);
				visited[item] = true;
				break;
			}
				
		}

		vector<string> answer;

		while (!q.empty())
		{
			string item = q.front();
			q.pop();
			answer.push_back(item);
			//visited[item] = true;

			for (string dst : adj[item])
			{
				indegrees[dst]--;
			}

			adj[item].clear();

			for (string item : items)
			{
				if (indegrees[item] == 0 && !visited[item])
				{
					q.push(item);
					visited[item] = true;
					break;
				}
			}
		}

		cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
		for (string item : answer)
			cout << ' ' << item;
		cout << ".\n\n";
	}
	return 0;
}
