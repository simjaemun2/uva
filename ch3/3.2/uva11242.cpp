#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <stack>

using namespace std;

#define MAX_N 100

int F,R;
double FF[MAX_N];
double RR;
double RRFF[MAX_N];
double spreads[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (true)
	{
		cin >> F;

		if (F == 0)
			break;

		cin >> R;

		for (int f = 0; f < F; f++)
		{
			cin >> FF[f];
		}
			

		int rrff_index = 0;

		for (int r = 0; r < R; r++)
		{
			cin >> RR;
			for (int f = 0; f < F; f++)
			{
				RRFF[rrff_index++] = RR / FF[f];
			}
		}
			
		sort(RRFF, RRFF+ rrff_index);

		double result = 1.0;

		for (int i = 1; i < rrff_index; i++)
		{
			result = max(result, RRFF[i] / RRFF[i - 1]);
		}

		printf("%.2lf\n", result);
	}

	


	
	return 0;
}