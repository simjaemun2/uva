#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>

using namespace std;

typedef long long int LL;
typedef pair<int, int > II;

const int MAX_N = 100;
const int MAX_P = 10000;
const int HALF = 5000;

int tc, TC;
int N, X;

int input[MAX_N + 1];
bool cache[MAX_P + 1];


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N >> X, N+X)
	{
		for (int n = 1; n <= N; n++)
		{
			int a, b;
			scanf("%d.%d", &a, &b);
			input[n] = a*100+b;
		}

		if (input[X] > HALF)
		{
			printf("100.00\n");
			continue;
		}

		memset(cache, 0, sizeof cache);
		cache[0] = true;
		
		for (int n = 1; n <= N; n++)
		{
			if (n != X)
			{
				for (int i = MAX_P - input[X]; i >= input[n]; i--)
				{
					cache[i] |= cache[i - input[n]];
				}
			}
		}

		int i = 5001 - input[X];
		for (; !cache[i]; i++);

		printf("%.2lf\n", (double)input[X] * 100 / (i + input[X]));
	}
	


	return 0;
}

