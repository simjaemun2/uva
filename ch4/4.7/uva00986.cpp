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

int N,R,K;

const int MAX_NRK = 20;

int cache[MAX_NRK*2 + 1][MAX_NRK + 1][MAX_NRK + 1][2];

const int DOWN = 0;
const int UP = 1;

int dp(int x, int y, int r, int prev)
{
	if (x == 0)
	{
		return r == 0 && y == 0 ? 1 : 0;
	}

	int& ret = cache[x][y][r][prev];

	if (ret != -1)
		return ret;
	
	ret = 0;

	if(y+1 <= N)
	{
		ret += dp(x - 1, y + 1, r, UP);
	}
	

	if(y)
	{
		if (y == K)
		{
			if (prev == UP)
			{
				if (r)
				{
					//cout << y << ' ' << x << ' ' << r << '\n';
					ret += dp(x - 1, y - 1, r - 1, DOWN);
				}
			}
			else
			{
				ret += dp(x - 1, y - 1, r, DOWN);
			}
		}
		else
		{
			ret += dp(x - 1, y - 1, r, DOWN);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> N >> R >> K)
	{
		memset(cache, -1, sizeof cache);
		cout << dp(2 * N, 0, R, UP) << '\n';
	}
	
	return 0;
}