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

int N, M;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	tc = 1;
	while (cin >> N >> M)
	{
		VVPII adj(N);

		for (int m = 0; m < M; m++)
		{
			int a, b, d;
			cin >> a >> b >> d;

			adj[a].push_back({ d, b });
			adj[b].push_back({ d, a });
		}

		VVI dist(2, VI(N, INF));
		dist[0][0] = 0;

		priority_queue<pair<int, PII > > pq;
		pq.push({ 0, {0, 0} });

		while (!pq.empty())
		{
			int d = -pq.top().first;
			int u = pq.top().second.first;
			int bi = pq.top().second.second;
			int nb = (bi + 1) % 2;
			pq.pop();

			if (dist[bi][u] >= d)
			{
				for (auto p : adj[u])
				{
					int v = p.second;
					int nd = d + p.first;

					if (dist[nb][v] > nd)
					{
						dist[nb][v] = nd;
						pq.push({ -nd, {v, nb} });
					}
				}
			}
		}

		cout << "Set #" << tc++ << '\n';

		int answer = INF;

		answer = min(dist[0][N - 1], answer);

		if (answer == INF)
		{
			cout << "?\n";
		}
		else
		{
			cout << answer << '\n';
		}
	}
	

	return 0;
}