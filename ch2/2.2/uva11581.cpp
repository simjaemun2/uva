#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define NUM_GRID 3
#define NUM_D 4
int N;
int grid[NUM_GRID][NUM_GRID];
int dx[NUM_D] = { -1,0,1,0 };
int dy[NUM_D] = { 0, -1, 0, 1 };

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;

	for (int t = 0; t < N; t++)
	{
		vector<vector<int> > prev(NUM_GRID, vector<int>(NUM_GRID));
		vector<vector<int> > next(NUM_GRID, vector<int>(NUM_GRID));
		int sum = 0;

		for (int i = 0; i < NUM_GRID; i++)
		{
			string line;
			cin >> line;
			for (int j = 0; j < NUM_GRID; j++)
			{
				prev[i][j] = line[j] - '0';
				sum += prev[i][j];
			}
		}

		if (sum == 0)
		{
			cout << -1 << '\n';
			continue;
		}
			

		int result = 0;

		while (true)
		{
			sum = 0;
			for (int i = 0; i < NUM_GRID; i++)
			{
				for (int j = 0; j < NUM_GRID; j++)
				{
					next[i][j] = 0;
					for (int d = 0; d < NUM_D; d++)
					{
						int nextY = i + dy[d];
						int nextX = j + dx[d];
						if (0 <= nextY && nextY < NUM_GRID
							&& 0 <= nextX && nextX < NUM_GRID)
						{
							next[i][j] += prev[nextY][nextX];
						}
					}
					next[i][j] %= 2;
					sum += next[i][j];
				}
			}

			if (sum == 0)
				break;

			prev.swap(next);

			result++;
		}
		cout << result << '\n';
	}


	return 0;
}