#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2000000000;
const int MAX_N = 1000;

int tc, TC;
int N;
int cache[MAX_N + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int n = 1; n <= MAX_N; n++)
	{
		cache[n] = INF;

		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				int c = n / (a * b);
				
				if (a*b*c == n)
				{
					cache[n] = min(cache[n], 2 * (a*b + b * c + c * a));
				}
			}
		}
	}

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		cout << cache[N] << '\n';
	}
	
	return 0;
}

