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

const int MAX_N = 10;
const int MAX_M = 100;

int tc, TC;
int N,M;
int L[MAX_N][MAX_M];
int cache[MAX_N][MAX_M + 1];

int dp(int n, int rt)
{
	if (n == N)
		return 0;
	
	if (rt <= 0)
		return -10000000;

	int& ret = cache[n][rt];

	if (ret != -1)
		return ret;

	ret = -10000000;

	for (int m = 0; m < rt; m++)
	{
		if (L[n][m] >= 5)
		{
			ret = max(ret, L[n][m] + dp(n + 1 ,rt - m - 1));
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
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> M;

		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				cin >> L[n][m];
			}
		}

		memset(cache, -1, sizeof cache);

		int answer = dp(0,M);

		if (answer >= 5 * N)
		{

			printf("Maximal possible average mark - %.2lf.\n", ((double)answer + 1e-9 )/ N);
		}
		else
		{
			printf("Peter, you shouldn't have played billiard that much.\n");
		}
	}


	return 0;
}

