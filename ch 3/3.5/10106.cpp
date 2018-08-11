#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX_N 200
#define MAX_M 10
#define MAX_D 20

typedef long long int LL;


LL input[MAX_N + 1];
LL cache[MAX_N + 1][MAX_M + 1][MAX_D + 1];


int N, Q;
int D, M;

LL dp()
{
	memset(cache, 0, sizeof(cache));

	cache[0][0][0] = 1;

	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m <= M; m++)
		{
			for (int d = 0; d < D; d++)
			{
				cache[n][m][d] += cache[n - 1][m][d];
				if (m)
				{
					//int t = (d + input[n]) % D;
					//if (t < 0) t += D;
					cache[n][m][d] += cache[n - 1][m - 1][(d + input[n]+D) % D];
				}
					
			}
		}
	}

	return cache[N][M][0];
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int s = 0;

	while (true)
	{
		cin >> N >> Q;
		if (N == 0 && Q == 0)
			return 0;

		cout << "SET " << ++s << ":" << '\n';

		for (int i = 1; i <= N; i++)
		{
			cin >> input[i];
		}

		for (int q = 1; q <= Q; q++)
		{
			cin >> D >> M;

			cout << "QUERY " << q << ": " << dp() << '\n';
		}
	}


	return 0;
}

