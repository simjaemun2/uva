#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 8

int N,RESULT;
int grid[MAX_N][MAX_N];
bool checked[MAX_N];
int sum;

void rec(int n)
{
	if (n == N)
	{
		RESULT = min(RESULT, sum);
	}
	else
	{
		for (int j = 0; j < N; j++)
		{
			if (!checked[j])
			{
				checked[j] = true;
				sum += grid[n][j];
				rec(n + 1);
				sum -= grid[n][j];
				checked[j] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		scanf("%d", &N);

		RESULT = N*N * 10000;
		sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &grid[i][j]);
			}
		}

		rec(0);

		printf("%d\n", RESULT);
	}
	

	return 0;
}

