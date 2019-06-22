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

int N, M, S;

const int MAX_N = 100;

int doors[MAX_N][MAX_N];
char board[MAX_N][MAX_N + 1];
char w2i[128];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	w2i['N'] = 0;
	w2i['W'] = 1;
	w2i['S'] = 2;
	w2i['E'] = 3;

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		VPII vd;

		cin >> N >> M;

		VVI dist(N, VI(M, INF));

		for (int n = 0; n < N; n++)
		{
			cin >> board[n];
			
			for (int m = 0; m < M; m++)
			{
				if (board[n][m] != '.' && board[n][m] != '#')
				{
					vd.push_back({ n, m });
				}
			}
		}

		for (auto p : vd)
		{
			cin >> S;
			doors[p.first][p.second] = S;
		}
		

		priority_queue<pair<int, PII > > pq;
		pq.push({ 0, {N - 1, 0} });
		dist[N - 1][0] = 0;

		while (!pq.empty())
		{
			int cy = pq.top().second.first;
			int cx = pq.top().second.second;
			int cd = -pq.top().first;

			pq.pop();

			if (cy == 0 && cx == M - 1)
			{
				continue;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int ny = cy + DY[d];
				int nx = cx + DX[d];

				if (0 <= ny && ny < N
					&& 0 <= nx && nx < M)
				{
					int step = 0;
						
					if (board[cy][cx] != '.')
					{
						step = abs(w2i[board[cy][cx]] - d) % 2 ? doors[cy][cx] : 2 * doors[cy][cx];
					}
						
					if (board[ny][nx] == '.')
					{
						int nd = cd + 1 + step;

						if (dist[ny][nx] > nd)
						{
							dist[ny][nx] = nd;
							pq.push({ -nd, {ny, nx} });
						}
					}
					else if (board[ny][nx] != '#')
					{
						if ((d + 2) % MAX_D == w2i[board[ny][nx]])
						{
							int nd = cd + 1 + step;

							if (dist[ny][nx] > nd)
							{
								dist[ny][nx] = nd;
								pq.push({ -nd, {ny, nx} });
							}
						}
					}
				}
			}
		}

		if (dist[0][M - 1] == INF)
		{
			cout << "Poor Kianoosh\n";
		}
		else
		{
			cout << dist[0][M - 1] << '\n';
		}
	}

	return 0;
}