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
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1};
int DX[] = {  0, -1, 0, 1 , -1,1,-1,1};

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int N, M, C, K;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> N >> M >> C >> K, N || M || C || K)
	{
		VVPII adj(N);

		for (int m = 0; m < M; m++)
		{
			int u, v, p;
			cin >> u >> v >> p;

			adj[u].push_back({ p, v });
			adj[v].push_back({ p, u });
		}

		VI dist(N, INF);
		dist[K] = 0;

		priority_queue<PII > pq;
		pq.push({ 0, K });

		while (!pq.empty())
		{
			int u = pq.top().second;
			int d = -pq.top().first;

			if (u == C - 1)
			{
				break;
			}

			pq.pop();

			if (dist[u] >= d)
			{
				for (auto p : adj[u])
				{
					int v = p.second;
					int nd = d + p.first;

					if (u < C)
					{
						if (u + 1 == v && dist[v] > nd)
						{
							dist[v] = nd;
							pq.push({ -nd, v });
						}
					}
					else
					{
						if (dist[v] > nd)
						{
							dist[v] = nd;
							pq.push({ -nd, v });
						}
					}
				}
			}
		}

		cout << dist[C - 1] << '\n';
	}
	
	return 0;
}