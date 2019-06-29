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
typedef pair<int, PII> PPII;
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;
typedef vector<double > VD;
typedef vector<PII> VPII;
typedef vector<vector<PII> > VVPII;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
//            N   W  S  E
//            0   1  2  3
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1 };
int DX[] = { 0, -1, 0, 1 , -1,1,-1,1 };

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int K, N;

const int MAX_N = 100;

int start;
VVI adj;
int cache[MAX_N + 1];
bool visited[MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	tc = 1;

	while (cin >> N, N)
	{
		cin >> start;
		memset(cache, 0, sizeof cache);
		memset(visited, false, sizeof visited);

		adj = VVI(N + 1);

		int u, v;
		while (cin >> u >> v, u || v)
		{
			adj[u].push_back(v);
		}

		int answer = 0;
		int answerIndex = start;

		queue<int> q({ start });

		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			visited[u] = false;
			
			
			for (int v : adj[u])
			{
				cache[v] = max(cache[v], cache[u] + 1);
				if (!visited[v])
				{
					visited[v] = true;
					q.push(v);
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (answer < cache[i])
			{
				answer = cache[i];
				answerIndex = i;
			}
		}

		cout << "Case " << tc++ << ": The longest path from " << start
			<< " has length " << answer << ", finishing at " << answerIndex << ".\n\n";
		
	}


	return 0;
}