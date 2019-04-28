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
const int MAX_N = 30;
const int MAX_D = 8;


int tc, TC;
int N;
char grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;

void dfs(int y, int x)
{
	grid[y][x] = '.';
	cnt++;
	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < N && 0 <= nx 
			&& grid[ny][nx] == '1')
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
	getline(cin, line);
	for (tc=1;tc<=TC;tc++)
	{
		if (tc > 1)
			cout << '\n';

		N = 0;

		while (getline(cin, line) && line.size())
		{
			for (int i = 0; i < line.size(); i++)
			{
				grid[N][i] = line[i];
			}
			grid[N][line.size()] = 0;
			N++;
		}

		int answer = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; grid[y][x]; x++)
			{
				if (grid[y][x] == '1')
				{
					cnt = 0;
					dfs(y, x);
					answer = max(cnt, answer);
				}
			}
		}

		cout << answer << '\n';
	}


	return 0;
}

