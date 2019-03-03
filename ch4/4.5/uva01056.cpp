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

#define INF 987654321

#define MAX_P 50

int P, R;

int graph[MAX_P + 1][MAX_P + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	
	while (cin >> P >> R, P + R)
	{

		for (int i = 0; i < P; i++)
		{
			for (int j = 0; j < P; j++)
			{
				graph[i][j] = INF;
			}

			graph[i][i] = 0;
		}

		map<string, int > m;
		vector<string > v;

		for (int i = 0; i < R; i++)
		{
			string a, b;
			cin >> a >> b;

			if (m.find(a) == m.end())
			{
				v.push_back(a);
				m[a] = v.size() - 1;
			}
			
			if (m.find(b) == m.end())
			{
				v.push_back(b);
				m[b] = v.size() - 1;
			}

			graph[m[a]][m[b]] = graph[m[b]][m[a]] = 1;
		}

		for (int k = 0; k < v.size(); k++)
		{
			for (int i = 0; i < v.size(); i++)
			{
				for (int j = 0; j < v.size(); j++)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}

		int answer = -1;

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				answer = max(answer, graph[i][j]);
			}
		}

		cout << "Network " << tc++ << ": ";

		if (answer == INF || v.size() < P)
			cout << "DISCONNECTED\n\n";
		else
			cout << answer << "\n\n";
	}




	return 0;
}