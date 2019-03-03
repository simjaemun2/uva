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

using namespace std;

typedef long long int LL;
typedef pair<int, int > II;

const int MAX_N = 10;

int tc, TC;
int SX, SY;
int N;
int X[MAX_N];
int Y[MAX_N];

int cache[MAX_N][1 << MAX_N];

int getDistance(int sx, int sy, int dx, int dy)
{
	return abs(sx - dx) + abs(sy - dy);
}

int dp(int pos, int mask)
{
	if (mask == (1 << N) - 1)
	{
		return getDistance(pos[X], pos[Y], SX, SY);
	}

	int& ret = cache[pos][mask];

	if (ret != -1)
		return ret;

	ret = 987654321;

	for (int n = 0; n < N; n++)
	{
		if (!(mask & (1 << n)))
		{
			ret = min(ret, getDistance(X[pos],Y[pos],X[n],Y[n]) + dp(n, mask | (1 << n)));
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> SX >> SY >> SX >> SY >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> X[n] >> Y[n];
		}

		memset(cache, -1, sizeof cache);

		int answer = 987654321;

		for (int n = 0; n < N; n++)
		{
			answer = min(answer, dp(n, 1 << n) + getDistance(X[n], Y[n], SX, SY));
		}

		cout << "The shortest path has length " << answer << '\n';
	}
	
	return 0;
}

