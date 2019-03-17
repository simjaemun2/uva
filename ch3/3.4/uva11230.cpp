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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_N = 100;


int tc, TC;
int N, M, R, C;
const int MAX_RC = 100;

bool input[MAX_RC][MAX_RC];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N >> M >> R >> C, N + M + R + C)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				char c;
				cin >> c;
				input[n][m] = c - '0';
			}
		}

		int answer = 0;

		for (int n = 0; n < N - R + 1; n++)
		{
			for (int m = 0; m < M - C + 1; m++)
			{
				if (input[n][m])
				{
					answer++;

					for (int r = n; r < n + R; r++)
					{
						for (int c = m; c < m + C; c++)
						{
							input[r][c] ^= true;
						}
					}
				}
			}
		}

		for (int n = 0; n < N && answer >= 0; n++)
		{
			for (int m = 0; m < M && answer >= 0; m++)
			{
				if (input[n][m])
				{
					answer = -1;
					break;
				}
			}
		}

		cout << answer << '\n';
	}
		
	
	return 0;
}