#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>

using namespace std;

int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);

		double result;

		if (N == 1)
			result = 0.0;
		else if (N == 2)
			result = 4.0;
		else
			result = (N - 2)*(N - 2)*sqrt(2) + N*N - (N - 2)*(N - 2);
		
		printf("%.3lf\n\n", result);

	}


	return 0;
}

