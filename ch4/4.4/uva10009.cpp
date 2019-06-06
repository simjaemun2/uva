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

const int MAX_N = 1000000;
int N, M;



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	//tc = 1;
	
	//while (cin >> N)

	cin >> TC;
	for(tc=1;tc<=TC;tc++)
	{
		
		if (tc != 1)
			cout << '\n';
			
		cin >> M >> N;

		map<string, VS > adj;

		for (int m = 0; m < M; m++)
		{
			string a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int n = 0; n < N; n++)
		{
			string u, v;
			cin >> u >> v;
			queue<pair<string, string > > q;
			q.push({u, string(1, u[0])});
			map<string, bool> visited;
			visited[u] = true;

			while (!q.empty())
			{
				string cur = q.front().first;
				string path = q.front().second;
				q.pop();

				if (cur == v)
				{
					cout << path << '\n';
					break;
				}

				for (string next : adj[cur])
				{
					if (!visited[next])
					{
						visited[next] = true;
						q.push({next, path + next[0]});
					}
				}
			}
		}
	}


	return 0;
}