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
//            S N W E
//            0 1 2 3
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};
const int SOUTH = 0;
const int NORTH = 1;
const int WEST = 2;
const int EAST = 3;

int N, M, K, Q;

const int MAX_C = 201;

int adj[MAX_C][MAX_C][MAX_D];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	while (cin >> N >> M, N != -1 && M != -1)
	{
		memset(adj, 0, sizeof adj);

		for (int n = 0; n < N; n++)
		{
			int X, Y, D, T;
			cin >> X >> Y >> D >> T;

			if (D)
			{
				for (int y = Y; y < Y + T; y++)
				{
					adj[y][X][WEST] = adj[y][X - 1][EAST] = -1;
				}
			}
			else
			{
				for (int x = X; x < X + T; x++)
				{
					adj[Y][x][SOUTH] = adj[Y - 1][x][NORTH] = -1;
				}
			}
		}

		for (int m = 0; m < M; m++)
		{
			int X, Y, D;
			cin >> X >> Y >> D;

			if (D)
			{
				adj[Y][X][WEST] = adj[Y][X - 1][EAST] = 1;
			}
			else
			{
				adj[Y][X][SOUTH] = adj[Y - 1][X][NORTH] = 1;
			}
		}

		double X, Y;
		cin >> X >> Y;
		int SY = (int)Y;
		int SX = (int)X;

		if (SY >= 200 || SX >= 200)
		{
			cout << "0\n";
			continue;
		}

		VVI dist(MAX_C, VI(MAX_C, INF));
		priority_queue<pair<int, PII> > pq;
		pq.push({ 0, {SY, SX} });

		dist[SY][SX] = 0;

		int answer = -1;

		while (!pq.empty())
		{
			int cd = -pq.top().first;
			int cy = pq.top().second.first;
			int cx = pq.top().second.second;

			pq.pop();

			if (dist[cy][cx] >= cd)
			{
				for (int d = 0; d < MAX_D; d++)
				{
					if (adj[cy][cx][d] >= 0)
					{
						int ny = cy + DY[d];
						int nx = cx + DX[d];

						if (0 <= ny && ny < MAX_C 
							&& 0 <= nx && nx < MAX_C 
							&& dist[ny][nx] > cd + adj[cy][cx][d])
						{
							dist[ny][nx] = cd + adj[cy][cx][d];
							pq.push({ -dist[ny][nx] , {ny, nx} });
						}
					}
				}
			}
		}

		if (dist[0][0] == INF)
			cout << "-1\n";
		else
			cout << dist[0][0] << '\n';
	}
	

	return 0;
}