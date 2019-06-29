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

int N;

const int MAX_N = 30;

int board[MAX_N + 1][MAX_N + 1][2];
LL cache[MAX_N + 1][MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		memset(board, -1, sizeof board);
		memset(cache, 0, sizeof cache);
		int sx, sy, ex, ey;


		cin >> N;
		cin >> sx >> sy >> ex >> ey;

		int a;
		cin >> a;
		while (a--)
		{
			int x, y;
			char c;
			cin >> x >> y >> c;

			if (c == 'S')
			{
				board[y][x][0] = 0;
			}
			else if (c == 'W')
			{
				board[y][x][1] = 0;
			}
			else if (c == 'E')
			{
				board[y][x+1][1] = 0;
			}
			else
			{
				board[y + 1][x][0] = 0;
			}
		}

		cache[sy][sx] = 1;

		for (int y = sy; y <= ey; y++)
		{
			for (int x = sx; x <= ex; x++)
			{
				if (board[y][x][0])
				{
					cache[y][x] += cache[y - 1][x];
				}

				if (board[y][x][1])
				{
					cache[y][x] += cache[y][x - 1];
				}
			}
		}

		cout << cache[ey][ex] << '\n';
	}
	
	return 0;
}