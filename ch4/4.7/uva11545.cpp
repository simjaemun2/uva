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

int N, K;

const int MAX_N = 1000;
const int MAX_T = 16;
const int MAX_H = 24;
const int REST = 8;
char input[MAX_N+1];
int cache[MAX_N + 1][MAX_T + 1][MAX_H + 1];

int dp(int n, int t, int h)
{
	if (n == N)
	{
		return 0;
	}

	int& ret = cache[n][t][h];
	if (ret != -1)
		return ret;
	ret = INF;


	if (t < MAX_T || n == N - 1)
	{
		if (!(input[n + 1] == '*' && ((h + 1) % MAX_H <= 6 || 18 <= (h + 1) % MAX_H)))
		{
			ret = min(ret, dp(n + 1, t + 1, (h + 1) % MAX_H) + 1);
		}
	}

	if (!(input[n] == '*' && ((h + REST) % MAX_H <= 6 || 18 <= (h + REST) % MAX_H)))
	{
		ret = min(ret, dp(n, 0, (h + REST) % MAX_H) + REST);
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
		memset(cache, -1, sizeof cache);

		cin >> input;
		N = strlen(input);

		cout << "Case #" << tc << ": ";

		int answer = dp(0, 0, 6);

		if (answer == INF)
			cout << "-1\n";
		else
			cout << answer-1 << '\n';
	}

	return 0;
}