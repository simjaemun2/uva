#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX_N 1000

int N, n;
string line;

char big[MAX_N][MAX_N];
char small[MAX_N][MAX_N];

void rotateClockWise90(char small[][MAX_N])
{
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			int t = small[n - j - 1][i];
			small[n - j - 1][i] = small[n - i - 1][n - j - 1];
			small[n - i - 1][n - j - 1] = small[j][n - i - 1];
			small[j][n - i - 1] = small[i][j];
			small[i][j] = t;
		}
	}
}

int getNumSquare(char big[][MAX_N], char small[][MAX_N])
{
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (big[i][j] == small[0][0])
			{
				int y = 0;
				for (; y < n; y++)
				{
					int x = 0;
					for (; x < n; x++)
					{
						if (big[i + y][j + x] != small[y][x])
							break;
					}
					if (x < n)
						break;
				}

				if (y == n)
					result++;
			}
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	/*
#define TTT 5
	for (int i = 0; i < TTT; i++)
	{
		for (int j = 0; j < TTT; j++)
		{
			small[i][j] = 'A' + i*TTT + j;
		}
	}
	n = TTT;
	for (int i = 0; i < TTT; i++)
	{
		cout << small[i] << '\n';
	}
	cout << endl << endl;
	rotateClockWise90(small);

	for (int i = 0; i < TTT; i++)
	{
		cout << small[i] << '\n';
	}


	return 0;
	*/
	while (cin >> N >> n)
	{
		if (N == 0)
			return 0;

		for (int i = 0; i < N; i++)
			cin >> big[i];
		for (int i = 0; i < n; i++)
			cin >> small[i];

		int degree0 = getNumSquare(big, small);
		rotateClockWise90(small);
		int degree90 = getNumSquare(big, small);
		rotateClockWise90(small);
		int degree180 = getNumSquare(big, small);
		rotateClockWise90(small);
		int degree270 = getNumSquare(big, small);

		printf("%d %d %d %d\n", degree0, degree90, degree180, degree270);
	}

	return 0;
}