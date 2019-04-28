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
int Y,X;
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

		if (0 <= ny && ny < Y && 0 <= nx && nx < X
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
	
	tc = 1;
	while(cin >> Y >> X, Y|X)
	{
		for (int y = 0; y < Y; y++)
		{
			cin >> grid[y];
		}

		vector<pair<int, char> > v;

		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if (grid[y][x] != '.')
				{
					char c = grid[y][x];
					cnt = 0;
					dfs(y, x, grid[y][x]);
					v.push_back({ -cnt, c });
				}
			}
		}

		
		sort(v.begin(), v.end());

		cout << "Problem " << tc++ << ":\n";

		for (auto p : v)
		{
			cout << p.second << ' ' << -p.first << '\n';
		}
	}
	

	return 0;
}

