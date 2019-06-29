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

int W, H, T;
const int MAX_WH = 100;

int board[MAX_WH + 2][MAX_WH + 2];
int cache[MAX_WH + 2][MAX_WH + 2];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> W >> H, W || H)
	{
		memset(board, -1, sizeof board);
		memset(cache, 0, sizeof cache);

		cin >> T;
		while (T--)
		{
			int y, x;
			cin >> x >> y;

			board[y+1][x+1] = 0;
		}

		cache[1][1] = 1;

		for (int y = 1; y <= H+1; y++)
		{
			for (int x = 1; x <= W + 1; x++)
			{
				if (board[y - 1][x])
				{
					cache[y][x] += cache[y - 1][x];
				}

				if (board[y][x - 1])
				{
					cache[y][x] += cache[y][x - 1];
				}
			}
		}

		if (cache[H+1][W+1] == 0)
		{
			cout << "There is no path.\n";
		}
		else if (cache[H + 1][W + 1] == 1)
		{
			cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
		}
		else
		{
			cout << "There are " << cache[H+1][W+1] << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
		}
	}
	
	return 0;
}