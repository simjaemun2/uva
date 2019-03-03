#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define NUM_LENGTH 8

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int M, N;
	while (cin >> M >> N, M)
	{
		int result;
		if (M == 1 || N == 1)
			result = max(M, N);
		else if(M == 2 || N == 2)
		{
			int X = max(M, N);
			if ((X - 1) % 4 == 0)
				result = (X - 1) / 4 * 4 + 2;
			else
				result = (X - 1) / 4 * 4 + 4;

		}
		else
		{
			result = ((M + 1) / 2) * ((N + 1) / 2) + (M / 2) * (N / 2);
		}
		
		printf("%d knights may be placed on a %d row %d column board.\n", result, M, N);
	}

			

	

	return 0;
}