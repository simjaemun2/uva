#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>
#include <math.h>

using namespace std;


#define INF 987654321
#define MAX_N 100
#define MAX_DIST 10000

int N;

double B, V, E, F;

int input[MAX_N+1];
int R;

double T[MAX_DIST + 1];
double cache[MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		for (int n = 1; n <= N; n++)
		{
			cin >> input[n];
			cache[n] = 0.0;
		}

		cin >> B >> R >> V >> E >> F;

		for (int x = 1; x <= R; x++)
		{
			T[x] = 1 / (V - F * (double)(R - (x-1))) + T[x-1];
		}

		for (int x = R + 1; x <= input[N]; x++)
		{
			T[x] = 1 / (V - E * (double)((x - 1) - R)) + T[x-1];
		}

		for (int i = 1; i <= N; i++)
		{
			cache[i] = 987654321.0;

			for (int j = 0; j < i; j++)
			{
				cache[i] = min(cache[i], cache[j] + T[input[i] - input[j]] + (j == 0 ? 0 : B));
			}
		}

		printf("%.4lf\n", cache[N]);
	}

	return 0;
}
