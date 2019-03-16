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

using namespace std;

const int MAX_N = 10;

const int MAX_D = 4;

 

int tc, TC;

int N;

char input[MAX_N][MAX_N + 1];
int dy[MAX_D] = { -1,1,0,0 };
int dx[MAX_D] = { 0,0,-1,1 };

 
int main(int argc, char** argv)

{

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}


		for (int y = 0; y < N; y++)
		{

			for (int x = 0; x < N; x++)
			{
				if (input[y][x] == '.')
				{
					for (int c = 'A'; c <= 'Z'; c++)
					{
						input[y][x] = c;

						int d = 0;

						for (; d < MAX_D; d++)
						{
							int ny = y + dy[d];
							int nx = x + dx[d];

							if (nx < 0 || nx == N || ny < 0 || ny == N)
								continue;

							if (c == input[ny][nx])
								break;

						}

 
						if (d == MAX_D)
							break;

					}
				}
			}
		}

 

		cout << "Case " << tc << ":\n";

		for (int n = 0; n < N; n++)
		{
			cout << input[n] << '\n';
		}

	}

 
 

	return 0;

}