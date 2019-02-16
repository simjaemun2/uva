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

using namespace std;

typedef long long int LL;

const int MAX_N = 1120;
const int MAX_K = 14;
int tc, TC;
int N, K;

vector<bool> isPrime(MAX_N + 1, true);
vector<int> primes;
int cache[500][MAX_N + 1][MAX_K + 1];

int dp(int p, int n, int k)
{
	if (k == 0)
	{
		if (n == 0)
			return 1;
		return 0;
	}

	if (p == primes.size() || primes[p] > n)
		return 0;

	int& ret = cache[p][n][k];

	if (ret != -1)
		return ret;

	ret = dp(p + 1, n, k);

	if (n >= primes[p])
	{
		ret += dp(p + 1, n - primes[p], k - 1);
	}

	return ret;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= MAX_N; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);

			for (int j = i * i; j <= MAX_N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	memset(cache, -1, sizeof cache);

	while (cin >> N >> K, N+K)
	{
		cout << dp(0, N, K) << '\n';
	}


	return 0;
}

