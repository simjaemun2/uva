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
const int MAX_N = 9;
const int MAX_D = 4;


int tc, TC;

char grid[MAX_N][MAX_N+1];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};


void dfsFill(int y, int x, char c)
{
	grid[y][x] = c;

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];
		if (0 <= ny && ny < MAX_N && 0 <= nx && nx < MAX_N
			&& (grid[ny][nx] == 'o' ||grid[ny][nx] == 'x' || grid[ny][nx] == '.' || grid[ny][nx] == 'n'))
		{
			dfsFill(ny, nx, c);
		}
	}
}

bool dfsCheck(int y, int x, char c)
{
	grid[y][x] = 'n';

	bool result = true;

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];
		if (0 <= ny && ny < MAX_N && 0 <= nx && nx < MAX_N)
		{
			if (c == 'o' && grid[ny][nx] == 'x' || c == 'x' && grid[ny][nx] == 'o')
			{
				return false;
			}
			else if(grid[ny][nx] != 'O' && grid[ny][nx] != 'X' && grid[ny][nx] != 'n')
			{
				result &= dfsCheck(ny, nx, c);
			}
		}
	}

	return result;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		for (int y = 0; y < MAX_N; y++)
			cin >> grid[y];

		vector<PII> vo,vx;

		for (int y = 0; y < MAX_N; y++)
		{
			for (int x = 0; x < MAX_N; x++)
			{
				int total = 0;
				int cnts[2] = { 0,0 };
				for (int d = 0; d < MAX_D; d++)
				{
					int ny = y + DY[d];
					int nx = x + DX[d];
					if (0 <= ny && ny < MAX_N && 0 <= nx && nx < MAX_N)
					{
						total++;
						if (grid[ny][nx] == 'O')
						{
							cnts[0]++;
						}
						else if (grid[ny][nx] == 'X')
						{
							cnts[1]++;
						}
					}
				}
				
				if (total == cnts[0])
				{
					grid[y][x] = 'O';
				}
				else if (total == cnts[1])
				{
					grid[y][x] = 'X';
				}
				else if (cnts[0] == 0 && cnts[1] == 0)
				{

				}
				else if (cnts[1] == 0)
				{
					if (grid[y][x] == '.')
					{
						grid[y][x] = 'o';
						vo.push_back({ y,x });
					}
				}
				else if (cnts[0] == 0)
				{
					if (grid[y][x] == '.')
					{
						grid[y][x] = 'x';
						vx.push_back({ y,x });
					}
				}
				else
				{
					if (grid[y][x] == '.')
					{
						dfsFill(y, x, 'N');
					}
				}
			}
		}

		for (auto p : vo)
		{
			int y = p.first;
			int x = p.second;

			if (grid[y][x] == 'o')
			{
				if (dfsCheck(y, x, 'o'))
				{
					dfsFill(y, x, 'O');
				}
				else
				{
					dfsFill(y, x, 'N');
				}
			}
		}

		for (auto p : vx)
		{
			int y = p.first;
			int x = p.second;

			if (grid[y][x] == 'x')
			{
				if (dfsCheck(y, x, 'x'))
				{
					dfsFill(y, x, 'X');
				}
				else
				{
					dfsFill(y, x, 'N');
				}
			}
		}

		int cnts[2] = {0,0};
		for (int y = 0; y < MAX_N; y++)
		{
			for (int x = 0;x < MAX_N; x++)
			{
				if (grid[y][x] == 'O')
					cnts[0]++;
				else if (grid[y][x] == 'X')
					cnts[1]++;
			}
		}

		cout << "Black " << cnts[1] << " White " << cnts[0] << '\n';
	}

	return 0;
}


