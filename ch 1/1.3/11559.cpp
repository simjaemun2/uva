#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>


using namespace std;

#define MAX_DRURATION 100

int N, B, W, H, P, A;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF)
	{
		int minPay = B + 1;
		for (int i = 0; i < H; i++)
		{
			scanf("%d", &P);
			int sum = 0;
			for (int j = 0; j < W; j++)
			{
				scanf("%d", &A);
				if (A >= N && P*N < minPay)
					minPay = P*N;
			}
			
		}

		if (minPay == B + 1)
			printf("stay home\n");
		else
			printf("%d\n", minPay);
			
	}

	
	

	return 0;
}