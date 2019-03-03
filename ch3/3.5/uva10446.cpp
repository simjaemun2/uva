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
const int MAX_N = 61;
const int MAX_BACK = 60;

int tc, TC;
int N,BACK;
ULL cache[MAX_N + 1][MAX_N + 1];

ULL dp(int n, int back)
{
	if (n <= 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 0;
	}

	ULL& ret = cache[n][back];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 1; i <= back; i++)
	{
		ret += dp(n - i, back) + 1;
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

	int tc = 1;

	while (cin >> N >> BACK, N <= 60)
	{
		cout << "Case " << tc++ << ": " << dp(N, BACK) + 1 << '\n';
	}
	
	return 0;
}

