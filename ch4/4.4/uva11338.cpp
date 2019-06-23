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

int W, H, N;
string SW;

const int MAX_N = 10000;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> SW, SW[0] != '*')
	{
		W = stoi(SW);
		cin >> H >> N;

		vector<PDD > v(N+2);
		vector<vector<pair<double, int> > > adj(N + 2);

		v[0].first = v[0].second = 0.0;
		v[1].first = H;
		v[1].second = W;

		for (int n = 2; n < N + 2; n++)
		{
			cin >> v[n].second >> v[n].first;

			for (int i = 0; i < n; i++)
			{
				double d = hypot(v[n].first - v[i].first, v[n].second - v[i].second);
				
				if (d <= 1.5)
				{
					adj[n].push_back({ d, i });
					adj[i].push_back({ d, n });
				}
			}
		}

		double D;
		cin >> D;

		VD dist(N + 2, INF);
		priority_queue<pair<double, int > > pq;
		dist[0] = 0.0;
		pq.push({ 0, 0 });

		while (!pq.empty())
		{
			int u = pq.top().second;
			double d = -pq.top().first;
			pq.pop();

			if (u == 1)
			{
				break;
			}

			for (auto p : adj[u])
			{
				int v = p.second;
				double nd = p.first + d;

				if (nd <= D && dist[v] > nd)
				{
					dist[v] = nd;
					pq.push({ -nd, v });
				}
			}
		}

		if (dist[1] == INF)
		{
			cout << "Boom!\n";
		}
		else
		{
			cout << "I am lucky!\n";
		}
	}

	return 0;
}