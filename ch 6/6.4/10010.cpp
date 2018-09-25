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
#include <locale>

using namespace std;

#define MAX_MN 50

int M, N;
string matrix[MAX_MN];
string line;

int ansR, ansC;

bool isVertical()
{
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r <= M - line.length(); r++)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r + i][c]) != toupper(line[i]))
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
	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c <= N - line.length(); c++)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r][c + i]) != toupper(line[i]))
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
	for (int r = 0; r <= M - line.length(); r++)
	{
		for (int c = 0; c <= N - line.length(); c++)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r + i][c + i]) != toupper(line[i]))
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
	for (int r = 0; r < M; r++)
	{
		for (int c = N - 1; c >= line.length() - 1; c--)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r][c - i]) != toupper(line[i]))
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
	for (int r = M - 1; r >= line.length() - 1; r--)
	{
		for (int c = N - 1; c >= line.length() - 1; c--)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r - i][c - i]) != toupper(line[i]))
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

bool isRVertical()
{
	for (int c = 0; c < N; c++)
	{
		for (int r = M - 1; r >= line.length() - 1; r--)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r - i][c]) != toupper(line[i]))
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

bool isLeftDown()
{
	for (int r = M - 1; r >= line.length(); r--)
	{
		for (int c = 0; c <= N - line.length(); c++)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r - i][c + i]) != toupper(line[i]))
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

bool isRightUp()
{
	for (int c = N - 1; c >= line.length(); c--)
	{
		for (int r = 0; r <= M - line.length(); r++)
		{
			if (toupper(matrix[r][c]) == toupper(line[0]))
			{
				int i = 1;

				for (; i < line.length(); i++)
				{
					if (toupper(matrix[r + i][c - i]) != toupper(line[i]))
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

	int T;
	cin >> T;
	while (T--)
	{
		cin >> M >> N;

		for (int i = 0; i < M; i++)
			cin >> matrix[i];

		int K;

		cin >> K;

		while (K--)
		{
			cin >> line;
			
			if (line.length() <= M && isVertical())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= N && isHorizontal())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= M && line.length() <= N && isDiagonal())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= N && isRHorizontal())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= M && line.length() <= N && isRDiagonal())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= M && line.length() <= N && isLeftDown())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= M && isRVertical())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
			else if (line.length() <= M && line.length() <= N && isRightUp())
			{
				cout << ansR + 1 << ' ' << ansC + 1 << '\n';
			}
		}

		if(T)
			cout << '\n';
	}

	

	return 0;
}
