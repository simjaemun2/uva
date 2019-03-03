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
typedef unsigned long long int ULL;
typedef pair<int, int > II;

const int INF = 2000000000;
const int MAX_LS = 10000;
const int ALPHA = 26;

int L, S;
int tc;

int cache[ALPHA+1][ALPHA + 1][MAX_LS];

int dp(int prev, int l, int s)
{
	if (l == 0)
	{
		return s == 0 ? 1 : 0;
	}

	if (s == 0)
	{
		return 0;
	}

	int& ret = cache[prev][l][s];

	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	for (int cur = prev + 1; cur <= ALPHA && cur <= s; cur++)
	{
		ret += dp(cur, l - 1, s - cur);
	}

	return ret;
}


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	memset(cache, -1, sizeof cache);

	while (cin >> L >> S, L)
	{
		cout << "Case " << ++tc << ": ";

		if (L > ALPHA)
		{
			cout << "0\n";
			continue;
		}

		cout << dp(0, L, S) << '\n';
	}
	

	return 0;
}

