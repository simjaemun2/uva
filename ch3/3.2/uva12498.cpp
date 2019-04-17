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


const int INF = 1000000;
const int MAX_RC = 50;

int tc, TC;
int R, C;

char input[MAX_RC + 1][MAX_RC + 1];
int moves[MAX_RC][MAX_RC];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> R >> C;

		for (int r = 0; r < R; r++)
		{
			cin >> input[r];

			for (int c = 0; c < C; c++)
				moves[r][c] = INF;

			for (int c = 0; c < C; c++)
			{
				if (input[r][c] == '0')
				{
					for (int k = 0; k < C; k++)
					{
						moves[r][k] = min(moves[r][k], abs(k - c));
					}
				}
			}
		}

		for (int r = 1; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				moves[r][c] += moves[r - 1][c];
			}
		}
		
		int answer = INF;

		for (int c = 0; c < C; c++)
		{
			answer = min(answer, moves[R - 1][c]);
		}

		if (answer == INF)
			answer = -1;

		cout << "Case " << tc << ": "  << answer << '\n';
	}
	return 0;
}
