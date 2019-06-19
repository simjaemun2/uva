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
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};

int N, M, K, Q;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{

		cin >> N >> M >> K;

		VB hasAirport(N + 1);
		VVPII adj(N + 1);

		for (int k = 0; k < K; k++)
		{
			int a;
			cin >> a;
			hasAirport[a] = true;
		}

		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v;
			
			adj[u].push_back({ !hasAirport[v], v });
			adj[v].push_back({ !hasAirport[u], u });
			
		}

		cout << "Case " << tc << ":\n";

		cin >> Q;

		while (Q--)
		{
			int a, b;
			cin >> a >> b;
			if (a == b)
			{
				cout << "0\n";
			}
			else
			{
				VI dist(N + 1, INF);
				priority_queue<PII> pq;
				pq.push({ 0, a });

				while (!pq.empty())
				{
					int u = pq.top().second;
					int d = -pq.top().first;
					pq.pop();
					
					if (dist[u] >= d)
					{
						for (auto p : adj[u])
						{
							int v = p.second;
							int nd = d + p.first;

							if (dist[v] > nd)
							{
								dist[v] = nd;
								pq.push({ -nd, v });
							}
						}
					}
				}

				if (dist[b] == INF)
				{
					cout << "-1\n";
				}
				else
				{
					cout << dist[b] + !hasAirport[a] << "\n";
				}
			}
		}

		cout << '\n';
	}
	

	return 0;
}