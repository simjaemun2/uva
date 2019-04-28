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
const int MAX_N = 90;
const int MAX_D = 4;


int tc, TC;
int N;
char grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;

void dfs(int y, int x, char c)
{
	grid[y][x] = c;

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < N && 0 <= nx 
			&& grid[ny][nx] == ' ')
		{
			dfs(ny, nx, c);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	string line;
	bool isFirst = true;
	while (getline(cin, line))
	{
		N = 0;
		if (!isFirst)
			cout << '\n';
		isFirst = false;


		for (int i = 0; i < line.size(); i++)
		{
			grid[N][i] = line[i];
		}
		grid[N][line.size()] = 0;
		N++;

		while (getline(cin, line), line[0] != '_')
		{
			for (int i = 0; i < line.size(); i++)
			{
				grid[N][i] = line[i];
			}
			grid[N][line.size()] = 0;
			N++;
		}

		getline(cin, line);
		

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; grid[y][x]; x++)
			{
				if (grid[y][x] != 'X' && grid[y][x] != ' ')
				{
					dfs(y, x, grid[y][x]);
				}
			}
		}

		for (int y = 0; y < N; y++)
		{
			cout << grid[y] << '\n';
		}

		cout << "_____________________________\n";
	}
	

	return 0;
}

