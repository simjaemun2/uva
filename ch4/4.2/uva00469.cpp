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
const int MAX_D = 8;


int tc, TC;
int N,M;
int answer;
char grid[MAX_N][MAX_N];

int DY[MAX_D] = { -1,-1,-1,0,0,1,1,1 };
int DX[MAX_D] = { -1,0,1,-1,1,-1,0,1 };

void dfs(int y, int x, char c)
{
	grid[y][x] = c == 'W' ? 'w' : 'W';
	answer++;

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < N
			&& 0 <= nx && nx < M
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

	getline(cin, line);
	
	TC = stoi(line);
	
	getline(cin, line);

	while (TC--)
	{
		N = 0;
		
		while (getline(cin, line), line[0] == 'L' || line[0] == 'W')
		{
			M = line.size();
			
			for (int m = 0; m < M; m++)
			{
				grid[N][m] = line[m];
			}
			N++;
		}

		istringstream iss(line);
		int y, x;
		iss >> y >> x;
		y--, x--;
		if (grid[y][x] == 'W' || grid[y][x] == 'w')
		{
			answer = 0;
			dfs(y, x, grid[y][x]);
			cout << answer << '\n';
		}
		else
		{
			cout << "0\n";
		}

		while (getline(cin, line) && line.size() > 0)
		{
			iss = istringstream(line);
			iss >> y >> x;
			y--, x--;
			if (grid[y][x] == 'W' || grid[y][x] == 'w')
			{
				answer = 0;
				dfs(y, x, grid[y][x]);
				cout << answer << '\n';
			}
			else
			{
				cout << "0\n";
			}
		}


		if (TC)
			cout << '\n';
	}

	return 0;
}

