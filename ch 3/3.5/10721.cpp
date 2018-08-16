#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

#define MAX_N 50


int N, M, K;
typedef long long int LL;

LL cache[MAX_N + 1][MAX_N + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> K >> M)
	{
		memset(cache, 0, sizeof(cache));

		for (int unit = 1; unit <= N && unit <= M; unit++)
			cache[1][unit] = 1;

		for (int k = 2; k <= K; k++)
		{
			for (int n = k; n <= N; n++)
			{
				for (int m = 1; m <= M && m < n; m++)
				{
					cache[k][n] += cache[k - 1][n - m];
				}
			}
		}

		cout << cache[K][N] << '\n';
	}
	
	
	return 0;
}

