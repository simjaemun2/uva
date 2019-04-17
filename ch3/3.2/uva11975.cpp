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
const int MAX_N = 75;
const int MAX_L = 1000;
const int MAX_V = 4;
const int MAX_C = 5;

const int LIMIT_CORNERS = 35;
const int LIMIT_MIDLINE = 40;
const int LIMIT_DIAGONALS = 45;

int tc, TC;
int N, L;

int V[MAX_V];
int C[MAX_C + 1][MAX_C + 1];
int SCORES[MAX_L];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin >> N >> L;

		map<int, int> m;

		for (int n = 1; n <= N; n++)
		{
			int a;
			cin >> a;
			m[a] = n;
		}

		for (int v = 0; v < MAX_V; v++)
		{
			cin >> V[v];
		}

		cout << "Case " << tc << ":\n";

		for (int l = 0; l < L; l++)
		{
			bool isMidLine = true;
			bool isDiagonals = true;
			bool isTab = true;

			for (int y = 0; y < MAX_C; y++)
			{
				for (int x = 0; x < MAX_C; x++)
				{
					cin >> C[y][x];

					C[y][x] = m[C[y][x]];

					if (!C[y][x])
						isTab = false;
				}

				if (!C[y][y] || C[y][y] > LIMIT_DIAGONALS
					|| !C[y][MAX_C - 1 - y] || C[y][MAX_C - 1 - y] > LIMIT_DIAGONALS)
				{
					isDiagonals = false;
				}
			}
			
			for (int x = 0; x < MAX_C; x++)
			{
				if (!C[2][x] || C[2][x] > LIMIT_MIDLINE)
				{
					isMidLine = false;
					break;
				}
			}

			bool isConers = (!C[0][0] || C[0][0] > LIMIT_CORNERS
				|| !C[0][MAX_C - 1] || C[0][MAX_C - 1] > LIMIT_CORNERS
				|| !C[MAX_C - 1][MAX_C - 1] || C[MAX_C - 1][MAX_C - 1] > LIMIT_CORNERS
				|| !C[MAX_C - 1][0] || C[MAX_C - 1][0] > LIMIT_CORNERS) ? false : true;

			SCORES[l] = 0;


			if (isConers)
			{
				SCORES[l] += V[0];
			}

			if (isMidLine)
			{
				SCORES[l] += V[1];
			}

			if (isDiagonals)
			{
				SCORES[l] += V[2];
			}

			if (isTab)
			{
				SCORES[l] += V[3];
			}

		}

		for (int l = 0; l < L; l++)
		{
			cout << SCORES[l] << '\n';
		}

	}

	return 0;
}
