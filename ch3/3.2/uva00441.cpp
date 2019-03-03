#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <stack>

using namespace std;

#define MAX_N 100

int K;
int input[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> K;

	while (true)
	{
		for (int k = 0; k < K; k++)
		{
			cin >> input[k];
		}

		for (int a = 0; a < K - 5; a++)
		{
			for (int b = a + 1; b < K - 4; b++)
			{
				for (int c = b + 1; c < K - 3; c++)
				{
					for (int d = c + 1; d < K - 2; d++)
					{
						for (int e = d + 1; e < K - 1; e++)
						{
							for (int f = e + 1; f < K; f++)
							{
								printf("%d %d %d %d %d %d\n", input[a], input[b], input[c], input[d], input[e], input[f]);
							}
						}
					}
				}
			}
		}

		cin >> K;
		if (K == 0)
			break;
		printf("\n");
	}

	


	
	return 0;
}