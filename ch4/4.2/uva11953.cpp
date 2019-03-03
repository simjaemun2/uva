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

#define MAX_N 100
#define MAX_D 4

int N;

char graph[MAX_N + 1][MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int T;
	cin >> T;
	for(int tc=1;tc<=T;tc++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> graph[i];

		int answer = 0;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (graph[y][x] == 'x' || graph[y][x] == '@')
				{
					bool alive = graph[y][x] == 'x' ? true : false;
					for (int i = x+1; i < N && (graph[y][i] == 'x' || graph[y][i] == '@'); i++)
					{
						if (graph[y][i] == 'x')
						{
							alive = true;
						}
						graph[y][i] = '.';
					}

					for (int i = y + 1; i < N && (graph[i][x] == 'x' || graph[i][x] == '@'); i++)
					{
						if (graph[i][x] == 'x')
						{
							alive = true;
						}
						graph[i][x] = '.';
					}

					if (alive)
						answer++;
				}
			}
		}

		cout << "Case " << tc << ": " << answer << '\n';
	}
	
	return 0;
}
