#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

#define MAX_N 100
#define MOD 1000000

int N, K;
typedef long long int LL;

LL cache[MAX_N + 1][MAX_N + 1];

LL dp(int n, int k)
{
	if (k == 1)
		return 1;
	LL& ret = cache[n][k];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i <= n; i++)
	{
		ret += dp(i, k - 1);
		ret %= MOD;
	}

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	memset(cache, -1, sizeof(cache));

	while (cin >> N >> K, N > 0 && K > 0)
		cout << dp(N, K) << '\n';
	
	
	return 0;
}

