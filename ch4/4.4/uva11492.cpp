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
#include <math.h>
#include <functional>

using namespace std;

#define MAX_M 2000
#define INF 987654321

int M;

string O, D;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> M, M)
	{
		cin >> O >> D;

		//cout << tc++ << ' ' << M << '\n';
 
		map<string, vector<string> > countries;
		map<string, vector<string > > adj;
		map<string, int> dist;

		for (int m = 0; m < M; m++)
		{
			string c1, c2, w;
			
			cin >> c1 >> c2 >> w;
			
			countries[c1].push_back(w);
			countries[c2].push_back(w);

			dist[w] = INF;
		}

		for (auto iter = countries.begin(); iter != countries.end(); iter++)
		{
			for (int i = 0; i < iter->second.size() - 1; i++)
			{
				string a = iter->second[i];
				for (int j = i + 1; j < iter->second.size(); j++)
				{
					string b = iter->second[j];

					if (a[0] != b[0])
					{
						adj[a].push_back(b);
						adj[b].push_back(a);
					}
				}
			}
		}

		string cs = "cs";
		string ce = "ce";

		dist[cs] = 0;
		dist[ce] = INF;

		for (string w : countries[O])
			adj[cs].push_back(w);

		for (string w : countries[D])
			adj[w].push_back(ce);

		priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;

		pq.push({ 0, cs });

		while (!pq.empty())
		{
			int d = pq.top().first;
			string u = pq.top().second;

			pq.pop();

			if (d > dist[u])
				continue;

			for (string v : adj[u])
			{
				if (dist[v] > dist[u] + v.length())
				{
					dist[v] = dist[u] + v.length();
					pq.push({ dist[v], v });
				}
			}
		}

		if (dist[ce] == INF)
			cout << "impossivel\n";
		else
			cout << dist[ce] - 2 << '\n';
	}

	return 0;
}