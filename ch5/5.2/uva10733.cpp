#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

double D, V, U;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%lf %lf %lf", &D, &V, &U);

		if (U == 0 || V == 0 || V >= U)
		{
			printf("Case %d: can't determine\n", tc);
			continue;
		}

		double fastest = D / U;
		double shortest = D / sqrt(U*U - V*V);

		printf("Case %d: %.3lf\n", tc, fabs(fastest - shortest));
	}
	
	
	return 0;
}

