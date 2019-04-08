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

const int MAX_N = 20000;
const int INF = 2000000000;
const int MAX_GRID = 1024;

int tc, TC;
int N, D;

int grid[MAX_GRID + 1][MAX_GRID + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	for (tc = 1;  tc <= TC; tc++)
	{
		memset(grid, 0, sizeof grid);

		cin >> D >> N;

		for (int n = 0; n < N; n++)
		{
			int X, Y, S;
			cin >> X >> Y >> S;

			int l = max(0, X - D);
			int r = min(MAX_GRID, X + D);
			int u = max(0, Y - D);
			int d = min(MAX_GRID, Y + D);

			for (int x = l; x <= r; x++)
			{
				for (int y = u; y <= d; y++)
				{
					grid[x][y] += S;
				}
			}
		}

		int maxSum = 0;
		int ax, ay;

		for (int x = 0; x <= MAX_GRID; x++)
		{
			for (int y = 0; y <= MAX_GRID; y++)
			{
				if (maxSum < grid[x][y])
				{
					maxSum = grid[x][y];
					ax = x, ay = y;
				}
			}
		}

		cout << ax << ' ' << ay << ' ' << maxSum << '\n';
	}

	return 0;
}
