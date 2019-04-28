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
int answer;
char grid[MAX_N][MAX_N];

int DY[MAX_D] = { -1,1,0,0};
int DX[MAX_D] = { 0,0,-1,1};

void dfs(int y, int x)
{
	grid[y][x] = '#';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (grid[ny][nx] == ' ')
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
	
	string line;

	getline(cin, line);
	
	TC = stoi(line);

	while (TC--)
	{
		N = 0;

		while (getline(cin, line) && line[0] != '_')
		{
			for (int i = 0; i < line.size(); i++)
			{
				grid[N][i] = line[i];
			}
			grid[N][line.size()] = 0;
			N++;
		}
		for (int i = 0; i < line.size(); i++)
		{
			grid[N][i] = line[i];
		}
		grid[N][line.size()] = 0;
		N++;

		bool hasStar = false;

		for (int n = 1; n < N-1 && !hasStar; n++)
		{
			for (int m = 1; grid[n][m]; m++)
			{
				if (grid[n][m] == '*')
				{
					dfs(n, m);
					break;
				}
			}
		}

		for (int n = 0; n < N; n++)
		{
			cout << grid[n] << '\n';
		}
	}

	return 0;
}

