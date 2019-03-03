#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <stack>

using namespace std;

#define MAX_N 1000

int N, A;
int input[MAX_N + 1];
int sum[MAX_N * MAX_N];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 1;

	while (true)
	{
		scanf("%d", &N);

		

		if (N == 0)
		{
			break;
		}

		printf("Case %d:\n", tc++);

		int sum_index = 0;

		for (int n = 0; n < N; n++)
		{
			scanf("%d", &input[n]);

			for (int i = 0; i < n; i++)
			{
				sum[sum_index++] = input[n] + input[i];
			}
		}


		int M;
		scanf("%d", &M);

		for (int m = 0; m < M; m++)
		{
			int F;
			scanf("%d", &F);

			int result = 999999999;
			int result_index;

			for (int i = 0; i < sum_index; i++)
			{
				if (result > abs(sum[i] - F))
				{
					result_index = i;
					result = abs(sum[i] - F);
				}
			}

			printf("Closest sum to %d is %d.\n", F, sum[result_index]);
		}
		
	}
	
	return 0;
}