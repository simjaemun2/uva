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
#include <functional>

using namespace std;

#define INF 987654321

#define MAX_AB 100

int A, B;

int graph[MAX_AB + 1][MAX_AB + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> A >> B, A + B)
	{
		for (int i = 1; i <= MAX_AB; i++)
		{
			for (int j = 1; j <= MAX_AB; j++)
			{
				graph[i][j] = INF;
			}
		}

		graph[A][B] = 1;

		while (cin >> A >> B, A + B)
		{
			graph[A][B] = 1;
		}

		for (int k = 1; k <= MAX_AB; k++)
		{
			for (int i = 1; i <= MAX_AB; i++)
			{
				for (int j = 1; j <= MAX_AB; j++)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}

		int sum = 0.0;
		int cnt = 0.0;

		for (int i = 1; i <= MAX_AB; i++)
		{
			for (int j = 1; j <= MAX_AB; j++)
			{
				if (i != j && graph[i][j] < INF)
				{
					sum += graph[i][j];
					cnt++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n", tc++, (double)sum / (double)cnt);
	}
	

	return 0;
}