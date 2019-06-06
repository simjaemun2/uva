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
	while (cin >> N)
	{
		/*
		if (tc != 1)
			cout << '\n';
		*/
		
		VVI adj(N + 1);

		for (int n = 0; n < N; n++)
		{
			int u, v;
			char t;
			string s;
			cin >> s;
			istringstream iss(s);
			iss >> u;
			while (iss >> t >> v)
			{
				adj[u].push_back(v);
			}
		}

		cout << "-----\n";

		cin >> M;

		while (M--)
		{
			int u, v;
			cin >> u >> v;
			VB visited(N + 1, false);
			queue<pair<int, string> > q;
			q.push({ u, to_string(u) });
			visited[u] = true;
			while (!q.empty())
			{
				int cur = q.front().first;
				string s = q.front().second;
				q.pop();

				if (cur == v)
				{
					cout << s << '\n';
					break;
				}

				for (int next : adj[cur])
				{
					if (!visited[next])
					{
						visited[next] = true;
						q.push({ next, s + ' ' + to_string(next) });
					}
				}
			}

			if (!visited[v])
			{
				cout << "connection impossible\n";
			}
		}
	}

	return 0;
}