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

int V,E;

vector<vector<int> > adj;
int visited[MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	while (T--)
	{
		cin >> V >> E;

		memset(visited, -1, sizeof visited);
		adj.clear();
		adj.resize(V);
		

		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		bool isPossible = true;
		int answer = 0;

		for (int i = 0; i < V && isPossible; i++)
		{
			if (visited[i] == -1)
			{
				queue<pair<int, int> > q;
				
				int cnt[2] = { 0, 0 };

				q.push({ i, 1 });
				visited[i] = 1;

				while (!q.empty() && isPossible)
				{
					int curNode = q.front().first;
					int curColor = q.front().second;
					q.pop();
					
					cnt[curColor]++;

					for (int nextNode : adj[curNode])
					{
						if (visited[nextNode] == -1)
						{
							q.push({ nextNode, 1 - curColor });
							visited[nextNode] = 1 - curColor;
						}
						else if (visited[nextNode] == curColor)
						{
							isPossible = false;
							break;
						}
					}
				}

				answer += max(1, min(cnt[0], cnt[1]));
			}
		}


		if (isPossible)
			cout << answer << '\n';
		else
			cout << -1 << '\n';
	}



	return 0;
}