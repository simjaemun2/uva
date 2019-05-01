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
const int MAX_Y = 10;
const int MAX_X = 15;
const int MAX_D = 4;


int tc, TC;
int W,H;
int cnt;

char grid[MAX_Y][MAX_X+1];
bool visited[MAX_Y][MAX_X + 1];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int X;

void dfs(int y, int x)
{
	visited[y][x] = true;
	cnt++;

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < MAX_Y && 0 <= nx && nx < X
			&& grid[y][x] == grid[ny][nx] && !visited[ny][nx])
		{
			dfs(ny, nx);
		}
	}
}

void dfs2(int y, int x, char c)
{
	grid[y][x] = ' ';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < MAX_Y && 0 <= nx && nx < X
			&& c == grid[ny][nx])
		{
			dfs2(ny, nx,c);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	

	for (tc = 1; tc <= TC; tc++)
	{
		for (int y = 0; y < MAX_Y; y++)
			cin >> grid[MAX_Y - y - 1];

		int remaining = MAX_X * MAX_Y;
		int move = 1;
		int scoreSum = 0;
		X = MAX_X;

		if (tc > 1)
			cout << '\n';
		cout << "Game " << tc << ":\n\n";

		while (true)
		{
			memset(visited, false, sizeof visited);

			int maxCnt = 1;
			int sy, sx;
			for (int x = 0; x < X; x++)
			{
				for (int y = 0; y < MAX_Y; y++)
				{
					if (!visited[y][x] && grid[y][x] != ' ')
					{
						cnt = 0;
						dfs(y, x);
					}

					if (maxCnt < cnt)
					{
						sy = y, sx = x, maxCnt = cnt;
					}
				}
			}

			if (maxCnt == 1)
				break;
			remaining -= maxCnt;

			int score = (maxCnt - 2)*(maxCnt - 2);
			scoreSum += score;

			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n"
			,move++, sy+1, sx+1, maxCnt, grid[sy][sx], score);
			
			dfs2(sy, sx, grid[sy][sx]);

			for (int x = 0; x < X; x++)
			{
				sy = 0;
				for (int y = 0; y < MAX_Y; y++)
				{
					if (grid[y][x] != ' ')
					{
						grid[sy++][x] = grid[y][x];
					}
				}
				if (sy)
				{
					for (; sy < MAX_Y; sy++)
					{
						grid[sy][x] = ' ';
					}
				}
				else
				{
					for (sx = x + 1; sx < X; sx++)
					{
						for (int y = 0; y < MAX_Y; y++)
						{
							grid[y][sx - 1] = grid[y][sx];
						}
					}
					X--, x--;
				}
			}
		}

		if (!remaining)
			scoreSum += 1000;

		printf("Final score: %d, with %d balls remaining.\n", scoreSum, remaining);
	}

	return 0;
}


