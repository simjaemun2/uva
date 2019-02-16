#define _CRT_SECURE_NO_WARNINGS 

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

using namespace std;

typedef long long int LL;

const int MAX_N = 1000;
const int MAX_W = 30;
const int MAX_G = 100;
int tc, TC;
int N, K, G;

int P[MAX_N];
int W[MAX_N];

int cache[MAX_G][MAX_N + 1];

int dp(int g, int n)
{
	if (n == N || g == 0)
		return 0;

	int& ret = cache[g][n];

	if (ret != -1)
		return ret;

	ret = dp(g, n + 1);

	if (g >= W[n])
	{
		ret = max(ret, dp(g - W[n], n + 1) + P[n]);
	}

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;

		memset(cache, -1, sizeof cache);

		for (int n = 0; n < N; n++)
		{
			cin >> P[n] >> W[n];
		}

		cin >> G;
		int sum = 0;
		for (int g = 0; g < G; g++)
		{
			int a;
			cin >> a;
			sum += dp(a, 0);
		}
		cout << sum << '\n';
	}


	return 0;
}

