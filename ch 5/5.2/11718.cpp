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

#define MAX_N 1000

int N, K, MOD;

long bigmod(long b, long p, long m)
{
	if (p == 0)
		return 1;
	else if (p % 2 == 0)
	{
		long a = bigmod(b, p / 2, m);
		return  a*a%m;
	}
	return (b % m) * bigmod(b, p - 1, m) % m;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K >> MOD;
		cout << "Case " << tc << ": ";

		//res = ( sum * n^(k-1) * k ) % mod

		long sum = 0;

		for (int n = 0; n < N; n++)
		{
			long a;
			cin >> a;
			sum += a;
			sum %= MOD;
		}
			
		long A = bigmod(N, K - 1, MOD);

		long res = (sum * A % MOD) * (K % MOD) % MOD;
		
		cout << res << '\n';


	}
	
	return 0;
}

