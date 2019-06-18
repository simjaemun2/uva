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

int N, M, Q;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	cin >> N >> M;

	VI fuelPrices(N);
	VVPII adj(N);


	for (int n = 0; n < N; n++)
	{
		cin >> fuelPrices[n];
	}

	for (int m = 0; m < M; m++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ d,v });
		adj[v].push_back({ d,u });
	}

	cin >> Q;

	for (int q = 0; q < Q; q++)
	{
		int C, S, E;
		cin >> C >> S >> E;

		priority_queue<pair<int, PII> > pq;
		VVI totalPrices(N, VI(C+1, INF));
		totalPrices[S][0] = 0;

		pq.push({ 0, {S, 0} });

		while (!pq.empty())
		{
			int tp = -pq.top().first;
			int u = pq.top().second.first;
			int c = pq.top().second.second;

			pq.pop();

			if (c + 1 <= C && totalPrices[u][c+1] > fuelPrices[u] + tp)
			{
				totalPrices[u][c + 1] = fuelPrices[u] + tp;
				pq.push({ -(fuelPrices[u] + tp), {u, c + 1} });
			}

			for (auto p : adj[u])
			{
				int dist = p.first;
				int v = p.second;

				if (c - dist >= 0 && totalPrices[v][c-dist] > tp)
				{
					totalPrices[v][c - dist] = tp;
					pq.push({ -tp, {v, c - dist} });
				}
			}
		}

		if (totalPrices[E][0] == INF)
			cout << "impossible\n";
		else
			cout << totalPrices[E][0] << '\n';
	}
	

	return 0;
}