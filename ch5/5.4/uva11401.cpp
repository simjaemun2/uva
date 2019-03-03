#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>



using namespace std;

#define MAX_N 1000000

int N;
long long int cache[MAX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	long long int acc = 0;

	for (int i = 4; i <= MAX_N; i++)
	{
		acc += (i - 2) / 2;
		cache[i] = cache[i - 1] + acc;
	}

	while (cin >> N, N >= 3)
	{
		cout << cache[N] << '\n';
	}
	

	return 0;
}