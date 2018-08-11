#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX_N 30000
#define NUM_COINS 5

int N;
unsigned long long int coins[] = {1,5,10,25,50};
unsigned long long int cache[MAX_N + 100];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cache[0] = 1;

	for (int j = 0; j < NUM_COINS; j++)
	{
		for (int i = coins[j]; i <= MAX_N; i++)
		{
			cache[i] += cache[i - coins[j]];
		}
	}


	while (cin >> N)
	{
		unsigned long long int ans = cache[N];

		if (ans == 1)
			cout << "There is only 1 way to produce " << N << " cents change.\n";
		else
			cout << "There are " << ans << " ways to produce " << N << " cents change.\n";
	}


	return 0;
}

