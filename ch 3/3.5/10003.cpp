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

const int INF = 987654321;
const int MAX_N = 50;
const int MAX_L = 1000;

int tc, TC;
int L, N;
int input[MAX_N+1];
int cache[MAX_N + 1][MAX_N + 1];


int dp(int l, int r)
{
	if (l + 1 == r)
		return 0;

	int& ret = cache[l][r];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = l + 1; i < r; i++)
	{
		ret = min(ret, dp(l, i) + dp(i, r) + input[r] - input[l]);
	}

	return ret;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> L, L)
	{
		cin >> N;

		for (int n = 1; n <= N; n++)
		{
			cin >> input[n];
		}

		N++;

		input[N] = L;

		memset(cache, -1, sizeof cache);

		cout << "The minimum cutting is " << dp(0, N) << ".\n";
	}
	
	
	
	return 0;
}

