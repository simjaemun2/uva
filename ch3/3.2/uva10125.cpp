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
#include <map>
#include <limits.h>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

int tc, TC;
int N;

const int MAX_N = 1000;
const int INF = 2000000000;

int input[MAX_N];

int binsearch(int l, int r, int v)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (input[m] < v)
			l = m + 1;
		else if (input[m] > v)
			r = m - 1;
		else
			return m;
	}

	return -1;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N,N)
	{
		for (int n = 0; n < N; n++)
			cin >> input[n];

		sort(input, input + N);

		int maxD = -INF;
		
		for (int a = 0; a < N - 2; a++)
		{
			for (int b = a + 1; b < N - 1; b++)
			{
				for (int c = b + 1; c < N; c++)
				{
					int v = input[a] + input[b] + input[c];
					int i = binsearch(0, N - 1, v);

					if (i >= 0 && input[i] != input[a] && input[i] != input[b] && input[i] != input[c])
					{
						if (input[i] > maxD)
						{
							maxD = input[i];
						}
					}
				}
			}
		}

		if (maxD == -INF)
			cout << "no solution\n";
		else
			cout << maxD << '\n';
	}

	return 0;
}
