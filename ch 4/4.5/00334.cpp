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

#define MAX_N 200

int NC,NE,NM;

bool graph[MAX_N][MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> NC, NC)
	{
		cout << "Case " << tc++ << ", ";

		memset(graph, false, sizeof graph);

		vector<string > v;
		map<string, int > m;

		for (int i = 0; i < NC; i++)
		{
			cin >> NE;
			string a, b;
			
			cin >> a;

			v.push_back(a);
			m[a] = v.size() - 1;

			for (int j = 1; j < NE; j++)
			{
				cin >> b;
				v.push_back(b);
				m[b] = v.size() - 1;

				graph[m[a]][m[b]] = true;

				a = b;
			}
		}

		cin >> NM;

		for (int i = 0; i < NM; i++)
		{
			string a, b;
			cin >> a >> b;

			graph[m[a]][m[b]] = true;
		}

		for (int k = 0; k < v.size(); k++)
		{
			for (int i = 0; i < v.size(); i++)
			{
				for (int j = 0; j < v.size(); j++)
				{
					graph[i][j] |= (graph[i][k] & graph[k][j]);
				}
			}
		}

		int cnt = 0;
		string result = "";

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (!(graph[i][j] || graph[j][i]))
				{
					cnt++;

					if (cnt <= 2)
					{
						result += '(' + v[i]  + ',' + v[j] + ") ";
					}
				}
			}
		}

		if (cnt)
		{
			cout << cnt << " concurrent events:\n" << result << '\n';
		}
		else
		{
			cout << "no concurrent events.\n";
		}
	}




	return 0;
}