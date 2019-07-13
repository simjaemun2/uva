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

int N, K;

const int MAX_N = 600;
const int MAX_K = 300;

VVI adj;

int input[MAX_N + 2];
int sum[MAX_N + 2];
int cache[MAX_N + 2][MAX_N + 2][MAX_K + 2];

int dp(int s, int e, int k)
{
	int& ret = cache[s][e][k];

	if (ret != -1)
		return ret;

	if (k == 0)
	{
		return ret = sum[e - 1] - sum[s - 1];
	}

	ret = INF;

	for (int i = s + 1; i < e && k - 1 < e - i; i++)
	{
		int a = dp(s, i, 0);
		int b = dp(i, e, k - 1);
		ret = min(ret, max(a, b));
	}

	return ret;

}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> N >> K)
	{
		memset(cache, -1, sizeof cache);

		for (int n = 1; n < N + 2; n++)
		{
			cin >> input[n];
			sum[n] = input[n] + sum[n - 1];
		}

		cout << dp(1, N + 2, K) << '\n';
	}

	return 0;
}