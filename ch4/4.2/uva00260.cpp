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
const int MAX_N = 200;
const int MAX_D = 6;

int tc, TC;
int N;

int DY[MAX_D] = { -1,-1, 0,0,1,1};
int DX[MAX_D] = { -1, 0,-1,1,0,1};

char grid[MAX_N][MAX_N + 1];
bool visited[MAX_N];

void dfs(int y, int x)
{
	if (grid[y][x] == 'b')
	{
		grid[y][x] = 'B';
		visited[y] = true;
	}
	else
	{
		grid[y][x] = 'W';
		visited[x] = true;
	}
		

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < N && 0 <= nx && nx < N)
		{
			if (grid[y][x] == 'B' && grid[ny][nx] == 'b'
				|| grid[y][x] == 'W' && grid[ny][nx] == 'w')
			{
				dfs(ny, nx);
			}
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	tc = 1;
	while (cin >> N, N)
	{
		for (int n = 0; n < N; n++)
			cin >> grid[n];

		char winner = 'n';

		for (int y = 0; y < N && winner == 'n'; y++)
		{
			for (int x = 0; x < N && winner == 'n'; x++)
			{
				if (grid[y][x] != '.')
				{
					memset(visited, false, sizeof visited);
					dfs(y, x);
					int n;
					for (n = 0; n < N && visited[n]; n++);
					if (n == N)
					{
						winner = grid[y][x];
					}
				}
			}
		}

		cout << tc++ << ' ' << winner << '\n';
	}

	
	return 0;
}

