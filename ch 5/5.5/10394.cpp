#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <sstream>
#include <bitset>
#include <iomanip>


using namespace std;

#define MAX_N 20000000 + 100
#define MAX_TWIN_PRIMES 100000

int N;

bool isNotPrime[MAX_N+1];
vector<long long int > primeNumbers;
vector<pair<long long int, long long int> > twinPrimes;

bool isPrime(long long int n)
{
	if (n <= MAX_N)
		return !isNotPrime[n];

	for (auto prime : primeNumbers)
	{
		if (n < prime)
			return true;
		if (n % prime == 0)
			return false;
	}

	return true;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	isNotPrime[0] = isNotPrime[1] = true;

	primeNumbers.push_back(2);

	for (long long int i = 3; i <= MAX_N; i += 2)
	{
		if (!isNotPrime[i])
		{
			if (primeNumbers.back() + 2 == i)
				twinPrimes.push_back({ primeNumbers.back(), i });

			primeNumbers.push_back(i);

			for (long long int j = i*i; j <= MAX_N; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}

	for (long long int i = primeNumbers.back() + 2; twinPrimes.size() < MAX_TWIN_PRIMES; i += 2)
	{
		if (isPrime(i))
		{
			if (primeNumbers.back() + 2 == i)
				twinPrimes.push_back({ primeNumbers.back(), i });
			primeNumbers.push_back(i);
		}
	}
	
	while (cin >> N)
	{
		cout << '(' << twinPrimes[N - 1].first << ", " << twinPrimes[N - 1].second << ")\n";
	}

	return 0;
}