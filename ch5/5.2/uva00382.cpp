#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	printf("PERFECTION OUTPUT\n");

	while (scanf("%d", &N), N)
	{
		printf("%5d  ", N);

		int sum = 1;

		for (int n = 2; n <= N / 2 + 1; n++)
		{
			if (!(N%n))
			{
				sum += n;
			}
		}
		if(N == 1)
			printf("DEFICIENT\n");
		else if (sum > N)
			printf("ABUNDANT\n");
		else if (sum == N)
			printf("PERFECT\n");
		else
			printf("DEFICIENT\n");
	}
	
	printf("END OF OUTPUT\n");

	return 0;
}

