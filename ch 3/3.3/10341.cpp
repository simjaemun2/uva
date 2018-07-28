#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int P, Q, R, S, T, U;

double func(double x)
{
	return P*exp(-x) + Q*sin(x) + R*cos(x) + S*tan(x) + T*x*x + U;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	double th = pow(10, -10);

	while (scanf("%d %d %d %d %d %d",&P,&Q,&R,&S,&T,&U) != EOF)
	{
		double l = 0.0;
		double r = 1.0;
		double m;

		if (func(l) * func(r) > 0)
		{
			printf("No solution\n");
			continue;
		}

		while (l + th < r)
		{
			m = (l + r) / 2.0;

			if (func(l) * func(m) > 0)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}

		printf("%.4lf\n", (l+r)/2.0);
	}
	

	return 0;
}

