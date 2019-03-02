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
const int MAX_NS = 65;
const int LOCKED = 1;
const int UNLOCKED = 0;

int N,S;

LL cache[MAX_NS + 1][MAX_NS + 1][MAX_NS + 1];

LL dp(int prev, int n, int s)
{
	if (n == 0)
	{
		return s == 0;
	}

	LL& ret = cache[prev][n][s];

	if (ret != -1LL)
	{
		return ret;
	}

	ret = 0LL;

	if (s == 0)
	{
		if (prev == UNLOCKED)
		{
			ret += dp(LOCKED, n - 1, s);
		}
		ret += dp(UNLOCKED, n - 1, s);
	}
	else
	{
		ret = dp(LOCKED, n - 1, s - prev);

		if (n > s)
		{
			ret += dp(UNLOCKED, n - 1, s);
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
	memset(cache, -1, sizeof cache);
	
	while (cin >> N >> S, N > 0)
	{
		cout << dp(LOCKED, N, S) << '\n';
	}
	

	return 0;
}

