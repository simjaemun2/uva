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

#define MAX_N 1000000

long long int A,B;

bool isNotPrime[MAX_N+1];
vector<int > primeNumbers;

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

	for (int i = 2; i <= sqrt(2147483647); i++)
	{
		if (!isNotPrime[i])
		{
			primeNumbers.push_back(i);

			for (int j = i*i; j <= MAX_N; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}
	
	while (cin >> A >> B)
	{
		int lastPrime = -1;

		int maxDiff = -1;
		int minDiff = MAX_N + 1;

		pair<long long int, long long int> minPair, maxPair;

		for (long long int i = A; i <= B; i++)
		{
			if (isPrime(i))
			{
				if (lastPrime == -1)
					lastPrime = i;
				else
				{
					int diff = i - lastPrime;

					if (diff > maxDiff)
					{
						maxDiff = diff;
						maxPair = { lastPrime, i };
					}

					if (diff < minDiff)
					{
						minDiff = diff;
						minPair = { lastPrime, i };
					}

					lastPrime = i;
				}
			}
		}

		/*
		2,3 are closest, 7,11 are most distant.
		
		*/

		if (maxDiff == -1)
			cout << "There are no adjacent primes.\n";
		else
		{
			cout << minPair.first << ',' << minPair.second << " are closest, ";
			cout << maxPair.first << ',' << maxPair.second << " are most distant.\n";
		}
		
	}

	return 0;
}