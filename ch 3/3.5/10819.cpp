#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_M 10200


int N, M;

int cache[MAX_M + 1][MAX_N + 1];
int P[MAX_N + 1];
int F[MAX_N + 1];

int dp(int m, int n)
{
	if (n == N)
		return 0;
	int& ret = cache[m][n];

	if (ret != -1)
		return ret;

	ret = dp(m, n+1);

	if (m + P[n] <= M)
		ret = max(ret, F[n] + dp(m + P[n], n + 1));
	else if(2000 < m+P[n] && m+P[n] <= M+200)
		ret = max(ret, F[n] + dp(m + P[n], n + 1));

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> M >> N)
	{
		memset(cache, -1, sizeof(cache));

		for (int n = 0; n < N; n++)
		{
			cin >> P[n] >> F[n];
		}

		cout << dp(0, 0) << '\n';
	}


	return 0;
}

