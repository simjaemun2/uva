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

int N;

bool isNotPrime[MAX_N+1];
vector<int > primeNumbers;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int i = 2; i <= 1000; i++)
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
	
	while (cin >> N, N)
	{
		int a = 1;
	
		for (; primeNumbers[a] <= N / 2 && isNotPrime[N - primeNumbers[a]]; a++);

		if (primeNumbers[a] > N / 2)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << N << " = " << primeNumbers[a] << " + " << N - primeNumbers[a] << '\n';
		
	}

	return 0;
}