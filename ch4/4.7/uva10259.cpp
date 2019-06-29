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
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1 };
int DX[] = { 0, -1, 0, 1 , -1,1,-1,1 };

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int K, N;

const int MAX_N = 100;

int cache[MAX_N][MAX_N];
int input[MAX_N][MAX_N];


int dp(int y, int x)
{
	int& ret = cache[y][x];
	
	if (ret != -1)
		return ret;

	ret = 0;

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];
		int k = 0;
		while (k < K && 0 <= ny && ny < N && 0 <= nx && nx < N)
		{
			if (input[y][x] < input[ny][nx])
			{
				ret = max(ret, dp(ny, nx));
			}

			ny += DY[d];
			nx += DX[d];
			k++;
		}
	}

	ret += input[y][x];

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
		if (tc != 1)
			cout << '\n';

		cin >> N >> K;

		memset(cache, -1, sizeof cache);

		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < N; m++)
			{
				cin >> input[n][m];
			}
		}

		cout << dp(0, 0) << '\n';
	}


	return 0;
}