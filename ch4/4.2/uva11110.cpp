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
const int MAX_N = 100;
const int MAX_D = 4;


int tc, TC;
int N;
char grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;

void dfs(int y, int x, char c)
{
	grid[y][x] = '.';
	
	cnt++;
	
	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (1 <= ny && ny <= N && 1 <= nx && nx <= N
			&& grid[ny][nx] == c)
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
	while (getline(cin, line), line[0] != '0')
	{
		N = stoi(line);
		memset(grid, 0, sizeof grid);

		bool good = true;

		for (int i = 1; i < N; i++)
		{
			int y, x;
			cnt = 0;
			getline(cin, line);
			istringstream iss(line);
			while (iss >> y >> x)
				grid[y][x] = i;
		}

		for (int y = 1; y <= N && good; y++)
		{
			for (int x = 1; x <= N && good; x++)
			{
				if (grid[y][x] != '.')
				{
					cnt = 0;

					dfs(y, x, grid[y][x]);
					
					if (cnt < N)
						good = false;
				}
			}
		}
		
		cout << (good ? "good\n" : "wrong\n");
	}
	

	return 0;
}

