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
int R,C;
char grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;

void dfs2(int y, int x)
{
	grid[y][x] = '*';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < C && 0 <= nx && nx < R
			&& grid[ny][nx] == 'X')
		{
			dfs2(ny, nx);
		}
	}
}

void dfs1(int y, int x)
{
	if (grid[y][x] == 'X')
	{
		cnt++;
		dfs2(y, x);
	}

	grid[y][x] = '.';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < C && 0 <= nx && nx < R
			&& grid[ny][nx] != '.')
		{
			dfs1(ny, nx);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	tc = 1;

	while (cin >> R >> C, R | C)
	{

		for (int r = 0; r < C; r++)
			cin >> grid[r];

		vector<int> answer;

		for (int y = 0; y < C; y++)
		{
			for (int x = 0; x < R; x++)
			{
				if (grid[y][x] != '.')
				{
					cnt = 0;
					dfs1(y, x);
					if (cnt)
						answer.push_back(cnt);
				}
			}
		}
		
		

		sort(answer.begin(), answer.end());

		cout << "Throw " << tc++ << '\n';

		cout << answer[0];

		for (int i = 1; i < answer.size(); i++)
		{
			cout << ' ' << answer[i];
		}

		cout << "\n\n";
	}

	return 0;
}

