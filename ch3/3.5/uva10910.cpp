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
const int MAX_NPT = 70;


int tc, TC;
int N, T, P;
int cache[MAX_NPT*2][MAX_NPT*2];


int dp(int n, int t)
{
	if (t == 0 || t == n)
		return 1;

	int& ret = cache[n][t];


	if (ret != -1)
		return ret;

	return ret = dp(n - 1, t - 1) + dp(n - 1, t);
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	memset(cache, -1, sizeof cache);
		
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> T >> P;

		T -= N * P;

		if (T < 0)
			cout << "0\n";
		else
			cout << dp(N + T - 1, N - 1) << '\n';
	}
	
	
	return 0;
}

