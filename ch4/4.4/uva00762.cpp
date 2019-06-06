#define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>
#include <map>
#include <limits.h>
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;

const int INF = 987654321;
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1 };
int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 100;
int N, M, P;

const int COST = 100;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	//cin >> TC;
	//for(tc=1;tc<=TC;tc++)
	
	//while(cin >> N >> M, N|M)
	tc = 1;
	while (cin >> N)
	{
		
		if (tc != 1)
			cout << '\n';
		tc++;
		map<string, int> indexes;
		VVI adj;
		VS vertices;

		string u, v;
		int iu, iv;

		for (int n = 0; n < N; n++)
		{
			cin >> u >> v;

			if (indexes.find(u) != indexes.end())
			{
				iu = indexes[u];
			}
			else
			{
				adj.push_back(VI());
				iu = indexes.size();
				indexes[u] = iu;
				vertices.push_back(u);
			}

			if (indexes.find(v) != indexes.end())
			{
				iv = indexes[v];
			}
			else
			{
				adj.push_back(VI());
				iv = indexes.size();
				indexes[v] = iv;
				vertices.push_back(v);
			}

			adj[iu].push_back(iv);
			adj[iv].push_back(iu);
		}
		
		cin >> u >> v;

		if (indexes.find(u) == indexes.end() || indexes.find(v) == indexes.end())
		{
			cout << "No route\n";
		}
		else
		{
			iu = indexes[u];
			iv = indexes[v];

			VB visited(indexes.size());
			visited[iu] = true;
			queue<pair<int, VI> > q;
			q.push({ iu, VI(1, iu) });

			while (!q.empty())
			{
				int cur = q.front().first;
				VI curIndexes = q.front().second;
				q.pop();
				if (cur == iv)
				{
					for (int i = 0; i < curIndexes.size() - 1; i++)
					{
						cout << vertices[curIndexes[i]] << ' ' << vertices[curIndexes[i + 1]] << '\n';
					}

					break;
				}

				for (int next : adj[cur])
				{
					if (!visited[next])
					{
						visited[next] = true;
						VI nextIndexes(curIndexes);
						nextIndexes.push_back(next);
						q.push({ next, nextIndexes });
					}
				}
			}

			if (!visited[iv])
			{
				cout << "No route\n";
			}
		}
	}

	return 0;
}
