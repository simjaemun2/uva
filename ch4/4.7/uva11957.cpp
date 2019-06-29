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

const int MAX_N = 100;
const int MOD = 1000007;

int N;
char board[MAX_N][MAX_N + 1];
int cache[MAX_N][MAX_N];

int dp(int y, int x)
{
	if (y == 0)
		return 1;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	ret = 0;

	if (0 <= x - 1)
	{
		if (board[y - 1][x - 1] == '.')
		{
			ret += dp(y - 1, x - 1);
			ret %= MOD;
		}
		else if (board[y - 1][x - 1] == 'B')
		{
			if (0 <= x - 2 && 0 <= y - 2 && board[y - 2][x - 2] == '.')
			{
				ret += dp(y - 2, x - 2);
				ret %= MOD;
			}
		}
	}

	if (x + 1 < N)
	{
		if (board[y - 1][x + 1] == '.')
		{
			ret += dp(y - 1, x + 1);
			ret %= MOD;
		}
		else if (board[y - 1][x + 1] == 'B')
		{
			if (x + 2 < N && 0 <= y - 2 && board[y - 2][x + 2] == '.')
			{
				ret += dp(y - 2, x + 2);
				ret %= MOD;
			}
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		int sy = -1 , sx;

		memset(cache, -1, sizeof cache);

		for (int n = 0; n < N; n++)
		{
			cin >> board[n];
			
			for (int m = 0; m < N && sy == -1; m++)
			{
				if (board[n][m] == 'W')
				{
					sy = n;
					sx = m;
				}
			}
		}

		cout << "Case " << tc << ": " << dp(sy, sx) << '\n';
	}
	
	return 0;
}