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

int C, S, E, T;

const int MAX_T = 1000;
const int MAX_C = 100;

int adj[MAX_C + 1][MAX_C + 1];
int cache[MAX_C + 1][MAX_T + 1];

int dp(int c, int t)
{
	int& ret = cache[c][t];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int nc = 1; nc <= C; nc++)
	{
		if (adj[c][nc])
		{
			ret = max(ret, dp(nc, t - 1) + adj[c][nc]);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	while (cin >> C >> S >> E >> T, C || E || S || T)
	{
		memset(cache, -1, sizeof cache);

		for (int i = 1; i <= C; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				cin >> adj[i][j];
			}
		}

		for (int e = 0; e < E; e++)
		{
			int a;
			cin >> a;
			cache[a][0] = 0;
		}

		for (int c = 1; c <= C; c++)
		{
			if (cache[c][0] == -1)
			{
				cache[c][0] = -INF;
			}
		}

		cout << dp(S, T) << '\n';
	}
	
	return 0;
}