#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

#define MAX_N 500000

int N;
int cache[MAX_N + 1];

int dp(int n)
{
	if (n == 1)
		return 1;
	int& ret = cache[n];
	if (ret > 0)
		return ret;

	if (n & 1)
		ret = (dp(n + 1) / 2 - 1) * 2;
	else
		ret = dp(n / 2) * 2;

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
		cout << dp(N) << '\n';


	return 0;
}

