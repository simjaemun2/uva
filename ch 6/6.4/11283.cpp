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


#define MAX_LEN 4
#define MAX_D 8

int dr[MAX_D] = { -1,-1,-1, 0,0, 1,1,1 };
int dc[MAX_D] = { -1, 0, 1,-1,1,-1,0,1 };


bool visited[MAX_LEN][MAX_LEN];
string matrix[MAX_LEN];
string line;
int N;
int answer;
bool founded;

void rec(int n, int r, int c)
{
	if (n == line.size())
	{
		if (n <= 4)
			answer++;
		else if (n == 5 || n == 6)
			answer += n - 3;
		else if (n == 7)
			answer += 5;
		else
			answer += 11;

		founded = true;
		return;
	}

	visited[r][c] = true;

	for (int d = 0; d < MAX_D && !founded; d++)
	{
		int nextR = r + dr[d];
		int nextC = c + dc[d];

		if (0 <= nextR && nextR < MAX_LEN
			&& 0 <= nextC && nextC < MAX_LEN
			&& !visited[nextR][nextC]
			&& matrix[nextR][nextC] == line[n])
		{
			rec(n + 1, nextR, nextC);
		}
	}

	visited[r][c] = false;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++)
	{
		for (int i = 0; i < MAX_LEN; i++)
		{
			cin >> matrix[i];
		}

		cin >> N;
		
		answer = 0;
		
		while (N--)
		{
			cin >> line;

			founded = false;

			for (int r = 0; r < MAX_LEN && !founded; r++)
			{
				for (int c = 0; c < MAX_LEN && !founded; c++)
				{
					if (matrix[r][c] == line[0])
						rec(1, r, c);
				}
			}
		}


		cout << "Score for Boggle game #" << tc << ": " << answer << '\n';
	}

	

	return 0;
}
