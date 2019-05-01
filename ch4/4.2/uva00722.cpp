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
const int MAX_D = 4;


int tc, TC;
int W,H;

char grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;
int Y, X;

void dfs(int y, int x)
{
	cnt++;
	grid[y][x] = 0;

	for (int d = 0; d < 4; d++)
	{
		int nx = DX[d] + x;
		int ny = DY[d] + y;

		if (0 <= ny && ny < Y && 0 <= nx && grid[ny][nx]
			&& grid[ny][nx] == '0')
			dfs(ny, nx);
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin.getline(grid[0], MAX_N);

	TC = stoi(grid[0]);

	cin.getline(grid[0], MAX_N);

	for (tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin.getline(grid[0], MAX_N);

		istringstream iss(string(grid[0], MAX_N));
		int sy, sx;
		iss >> sy >> sx;

		Y = 0;
		
		while (cin.getline(grid[Y], MAX_N) && strlen(grid[Y]))
		{
			Y++;
		}

		cnt = 0;
		dfs(sy - 1, sx - 1);
		cout << cnt << '\n';
	}



	return 0;
}


