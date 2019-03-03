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
#include <sstream>
#include <functional>

using namespace std;

typedef long long int LL;
typedef pair<int, int > II;

const int MAX_N = 10000;
const int MAX_W = 3000;

int tc, TC;
int N;
int W[MAX_W];
int L[MAX_W];
int cache[MAX_N][2*MAX_W+1];

int dp(int n, int l)
{
	if (n == N)
		return 0;

	int& ret = cache[n][l];

	if (ret != -1)
		return ret;

	ret = dp(n + 1, l);

	if (l >= W[n])
	{
		ret = max(ret, dp(n + 1, min(l - W[n], L[n]))+1);
	}

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N, N)
	{
		for (int n = 0; n < N; n++)
		{
			cin >> W[n] >> L[n];
		}

		memset(cache, -1, sizeof cache);

		int answer = dp(0, 2 * MAX_W);

		cout << answer << '\n';
	}


	return 0;
}

