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
int H,W;
int answer;
char grid[MAX_N][MAX_N];

int DY[MAX_D] = { -1,1,0,0};
int DX[MAX_D] = { 0,0,-1,1};

int cnt[128];


bool compare(const pair<int, char>& a, const pair<int, char>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

void dfs(int y, int x, int c)
{
	grid[y][x] = '#';

	for (int d = 0; d < MAX_D; d++)
	{
		int ny = y + DY[d];
		int nx = x + DX[d];

		if (0 <= ny && ny < H && 0 <= nx && nx < W && grid[ny][nx] == c)
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
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> H >> W;
		for (int h = 0; h < H; h++)
		{
			cin >> grid[h];
		}

		memset(cnt, 0, sizeof cnt);

		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				if (grid[y][x] != '#')
				{
					cnt[grid[y][x]]++;
					dfs(y, x, grid[y][x]);
				}
					
			}
		}

		vector<pair<int, char> > v;

		for (int i = 'a'; i <= 'z'; i++)
		{
			if (cnt[i])
			{
				v.push_back({ cnt[i], i });
			}
		}

		sort(v.begin(), v.end(), compare);

		cout << "World #" << tc << '\n';

		for (auto p : v)
		{
			cout << p.second << ": " << p.first << '\n';
		}
	}

	return 0;
}

