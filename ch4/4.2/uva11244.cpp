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
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 987654321;
const int MAX_N = 110;
const int MAX_D = 8;


int tc, TC;
int R,C;
char grid[MAX_N][MAX_N];

int DY[MAX_D] = { -1,1,0,0,-1,-1,1,1};
int DX[MAX_D] = { 0,0,-1,1,-1,1,-1,1};

bool isStar;


void dfs(int y, int x)
{
	grid[y][x] = '.';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < R && 0 <= nx && nx < C && grid[ny][nx] == '*')
		{
			isStar = false;
			dfs(ny, nx);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> R >> C, R | C)
	{
		for (int r = 0; r < R; r++)
			cin >> grid[r];

		int answer = 0;

		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				if (grid[y][x] == '*')
				{
					isStar = true;
					dfs(y, x);
					answer += isStar ? 1 : 0;
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}

