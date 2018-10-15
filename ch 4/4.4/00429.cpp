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

int N,R;



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;

	cin.ignore();

	for(int tc=0; tc<T; tc++)
	{
		if(tc)
			cout << '\n';

		map<string, vector<string> > adj;
		vector<string> nodes;

		string line;

		while(getline(cin, line), line != "*")
		{
			for (string node: nodes)
			{
				if (node.length() == line.length())
				{
					int cnt = 0;

					for (int i = 0; i < node.length(); i++)
					{
						if (line[i] == node[i])
							cnt++;
					}

					if (cnt == node.length() - 1)
					{
						adj[node].push_back(line);
						adj[line].push_back(node);
					}
				}
			}

			nodes.push_back(line);
		}

		while (getline(cin, line) && line != "")
		{
			stringstream ss(line);
			string src, dst;
			ss >> src >> dst >> dst;

			map<string, bool> visited;

			queue<pair<string, int> > q;

			visited[src] = true;
			q.push({ src, 0 });

			while (!q.empty())
			{
				string node = q.front().first;
				int steps = q.front().second;

				q.pop();

				if (node == dst)
				{
					cout << src << ' ' << dst << ' ' << steps << '\n';
					break;
				}

				for (string nextNode : adj[node])
				{
					if (!visited[nextNode])
					{
						visited[nextNode] = true;
						q.push({ nextNode, steps + 1 });
					}
				}
			}

		}

		
	}


	return 0;
}
