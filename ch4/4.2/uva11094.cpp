#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>

using namespace std;

#define MAX_MN 20
#define MAX_D 4

int M, N, X, Y;
char graph[MAX_MN][MAX_MN + 2];
int color[MAX_MN][MAX_MN];

int dy[MAX_D] = { -1,1,0,0 };
int dx[MAX_D] = { 0,0,-1,1 };

int curSize;

char land;

void exclude(int x, int y)
{
	color[x][y] = 1;
	
	for (int d = 0; d < MAX_D; d++)
	{
		int nextX = x + dx[d];
		int nextY = (y + dy[d] + N) % N;

		if (0 <= nextX && nextX < M
			&& graph[nextX][nextY] == land
			&& color[nextX][nextY] == 0)
		{
			exclude(nextX, nextY);
		}
	}
}

void fill(int x, int y)
{
	color[x][y] = 1;
	curSize++;
	for (int d = 0; d < MAX_D; d++)
	{
		int nextX = x + dx[d];
		int nextY = (y + dy[d] + N) % N;

		if (0 <= nextX && nextX < M
			&& graph[nextX][nextY] == land
			&& color[nextX][nextY] == 0)
		{
			fill(nextX, nextY);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> M >> N)
	{
		for (int i = 0; i < M; i++)
			cin >> graph[i];
		cin >> X >> Y;

		land = graph[X][Y];

		memset(color, 0, sizeof color);

		exclude(X, Y);

		int ansSize = 0;
		
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == land && color[i][j] == 0)
				{
					curSize = 0;
					fill(i, j);

					if (curSize > ansSize)
						ansSize = curSize;
				}
			}
		}

		cout << ansSize << '\n';
	}
	
	return 0;
}
