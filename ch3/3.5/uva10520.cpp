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
const int MAX_N = 20;

int tc, TC;
int N, A;

LL cache[MAX_N + 1][MAX_N + 1];

LL dp(int i, int j)
{

	LL& ret = cache[i][j];

	if (ret != -1)
		return ret;

	if (i >= j)
	{
		LL left = 0;
		LL right = 0;

		if (i != N)
		{
			for (int k = i + 1; k <= N; k++)
			{
				left = max(left, dp(k, 1) + dp(k, j));
			}
		}
		
		if (j != 0)
		{
			for (int k = 1; k < j; k++)
			{
				right = max(right, dp(i, k) + dp(N, k));
			}
		}

		ret = left + right;
	}
	else
	{
		ret = 0;

		for (int k = i; k < j; k++)
		{
			ret = max(ret, dp(i, k) + dp(k + 1, j));
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

	while (cin >> N >> A)
	{
		memset(cache, -1, sizeof cache);

		cache[N][1] = A;

		cout << dp(1, N) <<'\n';
	}

	return 0;
}

