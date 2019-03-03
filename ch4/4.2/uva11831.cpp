#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;

#define MAX_MN 100
#define MAX_D 4

int N, M, S;




char input[MAX_MN + 2][MAX_MN + 2];
string line;
//                  O   N  L  S
int dirR[MAX_D] = { 0, -1, 0, 1};
int dirC[MAX_D] = { -1, 0, 1, 0 };

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> M >> S, N + M + S)
	{
		int cr, cc,d;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> input[i][j];

				if (input[i][j] == 'N')
				{
					cr = i, cc = j;
					d = 1;
					input[i][j] = '.';
				}
				
				if (input[i][j] == 'O')
				{
					cr = i, cc = j;
					d = 0;
					input[i][j] = '.';
				}

				if (input[i][j] == 'S')
				{
					cr = i, cc = j;
					d = 3;
					input[i][j] = '.';
				}

				if (input[i][j] == 'L')
				{
					cr = i, cc = j;
					d = 2;
					input[i][j] = '.';
				}
			}
		}
			

		cin >> line;

		int sum = 0;

		for (char c : line)
		{
			if (c == 'D')
			{
				d = (d + 1) % MAX_D;
			}
			else if (c == 'E')
			{
				d = (d + MAX_D - 1) % MAX_D;
			}
			else//F
			{
				int nextR = cr + dirR[d];
				int nextC = cc + dirC[d];

				if (0 <= nextR && nextR < N && 0 <= nextC && nextC < M)
				{
					if (input[nextR][nextC] == '.')
					{
						cr = nextR, cc = nextC;
					}
					else if (input[nextR][nextC] == '*')
					{
						cr = nextR, cc = nextC;
						sum++;
						input[cr][cc] = '.';
					}
				}
			}
		}

		cout << sum << '\n';
	}
	
	
	//No common sequence.
	return 0;
}
