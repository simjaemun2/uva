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


const int INF = 2000000000;
const int MAX_N = 223;

int tc, TC;
int N;

int T[MAX_N + 1];

int bsearch(int l, int r, int v)
{
	while(l <= r)
	{
		int m = l + (r - l) / 2;

		if (v < T[m])
			r = m - 1;
		else if (v > T[m])
			l = m + 1;
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

	for (int n = 0; n <= MAX_N; n++)
		T[n] = n * n;

	cin >> TC;
	while (TC--)
	{
		cin >> N;

		bool isPossible = false;

		for (int a = 0; 3*T[a] <= N && !isPossible; a++)
		{
			for (int b = a; T[a] + 2*T[b] <= N && !isPossible; b++)
			{
				int c = bsearch(b, MAX_N, N - T[a] - T[b]);

				if (c >= b)
				{
					isPossible = true;
					cout << a << ' ' << b << ' ' << c << '\n';
				}
			}
		}

		if (!isPossible)
			cout << "-1\n";
	}

	

	return 0;
}
