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
const int MAX_N = 60;
const int MAX_D = 4;


int tc, TC;
int W,H;

char grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;

void dfs(int y, int x)
{
	if (grid[y][x] == 'G')
		cnt++;

	grid[y][x] = '#';

	for (int d = 0; d < 4; d++)
	{
		int nx = DX[d] + x;
		int ny = DY[d] + y;

		if (grid[ny][nx] == 'T')
			return;
	}

	for (int d = 0; d < 4; d++)
	{
		int nx = DX[d] + x;
		int ny = DY[d] + y;

		if (grid[ny][nx] == '.' || grid[ny][nx] == 'G')
			dfs(ny, nx);
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> W >> H)
	{
		for (int h = 0; h < H; h++)
		{
			cin >> grid[h];
		}

		cnt = -1;

		for (int y = 1; y < H - 1 && cnt < 0; y++)
		{
			for (int x = 1; x < W - 1; x++)
			{
				if (grid[y][x] == 'P')
				{
					cnt = 0;
					dfs(y, x);
					break;
				}
			}
		}

		cout << cnt << '\n';
	}



	return 0;
}


