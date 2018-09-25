#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <math.h>

using namespace std;

#define MAX_N 100

int N;ac
string matrix[MAX_N];
string line;

int ansR, ansC;

bool isVertical()
{
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r <= N - line.length(); r++)
		{
			if (matrix[r][c] == line[0])
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (matrix[r + i][c] != line[i])
						break;
				}

				if (i == line.length())
				{
					ansR = r;
					ansC = c;
					return true;
				}
			}
		}
	}
	
	return false;
}

bool isHorizontal()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c <= N - line.length(); c++)
		{
			if (matrix[r][c] == line[0])
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (matrix[r][c+i] != line[i])
						break;
				}

				if (i == line.length())
				{
					ansR = r;
					ansC = c;
					return true;
				}
			}
		}
	}

	return false;
}

bool isDiagonal()
{
	for (int r = 0; r <= N - line.length(); r++)
	{
		for (int c = 0; c <= N - line.length(); c++)
		{
			if (matrix[r][c] == line[0])
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (matrix[r + i][c + i] != line[i])
						break;
				}

				if (i == line.length())
				{
					ansR = r;
					ansC = c;
					return true;
				}
			}
		}
	}

	return false;
}

bool isRHorizontal()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = N - 1; c >= line.length() - 1; c--)
		{
			if (matrix[r][c] == line[0])
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (matrix[r][c - i] != line[i])
						break;
				}

				if (i == line.length())
				{
					ansR = r;
					ansC = c;
					return true;
				}
			}
		}
	}

	return false;
}

bool isRDiagonal()
{
	for (int r = N - 1; r >= line.length() - 1; r--)
	{
		for (int c = N - 1; c >= line.length() - 1; c--)
		{
			if (matrix[r][c] == line[0])
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (matrix[r - i][c - i] != line[i])
						break;
				}

				if (i == line.length())
				{
					ansR = r;
					ansC = c;
					return true;
				}
			}
		}
	}

	return false;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> matrix[i];
	
	while (cin >> line, line != "0")
	{
		if (line.length() > N)
			cout << "Not found\n";
		else
		{
			if (isVertical())
			{
				ansR++;
				ansC++;
				printf("%d,%d %d,%d\n", ansR, ansC, ansR + line.length() - 1, ansC);
			}
			else if (isHorizontal())
			{
				ansR++;
				ansC++;
				printf("%d,%d %d,%d\n", ansR, ansC, ansR, ansC + line.length() - 1);
			}
			else if (isDiagonal())
			{
				ansR++;
				ansC++;
				printf("%d,%d %d,%d\n", ansR, ansC, ansR + line.length() - 1, ansC + line.length() - 1);
			}
			else if (isRHorizontal())
			{
				ansR++;
				ansC++;
				printf("%d,%d %d,%d\n", ansR, ansC, ansR, ansC - line.length() + 1);
			}
			else if (isRDiagonal())
			{
				ansR++;
				ansC++;
				printf("%d,%d %d,%d\n", ansR, ansC, ansR - line.length() + 1, ansC - line.length() + 1);
			}
			else
			{
				printf("Not found\n");
			}
		}
	}

	return 0;
}
