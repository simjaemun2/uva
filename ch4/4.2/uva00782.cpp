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
const int MAX_Y = 32;
const int MAX_X = 85;
const int MAX_D = 4;


int tc, TC;
int W,H;

char grid[MAX_Y][MAX_X];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;
int Y;

void dfs(int y, int x)
{
	grid[y][x] = grid[y][x] == '.' ? '#' : '*';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < Y && 0 <= nx && nx < MAX_X-2
			&& (grid[ny][nx] == '.' || grid[ny][nx] == ' '))
		{
			dfs(ny, nx);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	cin.ignore();

	for (tc = 1; tc <= TC; tc++)
	{
		memset(grid, 0, sizeof grid);
		
		Y = 0;

		for (Y = 0; cin.getline(grid[Y], MAX_X) && grid[Y][0] != '_'; Y++);
		
		int sy=-1, sx=-1;
		for (int y = 0; y < Y; y++)
		{
			int x;
			for (x = 0; x < MAX_X-2; x++)
			{
				if (grid[y][x] == '*')
				{
					sy = y, sx = x;
					grid[y][x] = ' ';
				}

				if (!grid[y][x])
				{
					grid[y][x] = ' ';
				}

				if (grid[y][x] == ' ')
				{
					for (int d = 0; d < MAX_D; d++)
					{
						int ny = y + DY[d];
						int nx = x + DX[d];

						if (0 <= ny && ny < Y && 0 <= nx && nx < MAX_X-2
							&& grid[ny][nx] == 'X')
						{
							grid[y][x] = '.';
						}
					}
				}
			}
			
		}

		if (sy >= 0)
		{
			dfs(sy, sx);
		}

		for (int y = 0; y < Y+1; y++)
		{
			for (int x = 0; x < MAX_X-2; x++)
			{
				if (grid[y][x] == '.' || grid[y][x] == '*')
					grid[y][x] = ' ';
			}
		}

		for (int y = 0; y < Y+1; y++)
		{
			int x;
			for (x = strlen(grid[y]); grid[y][x] == ' '; x--);
			grid[y][x + 1] = 0;
			cout << grid[y] << '\n';
		}
	}

	return 0;
}


