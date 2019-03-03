#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

#define MAX_N 100
#define BLACK 1
#define WHITE -1

int M, N, K;
vector<int> edge[MAX_N+1];
int color[MAX_N+1];
int maxBlack;
vector<int> solution;

void rec(int n)
{
	if (n == N+1)
	{
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if (color[i] == BLACK)
				sum += 1;
		}

		if (maxBlack < sum)
		{
			solution.clear();
			maxBlack = sum;
			for (int i = 1; i <= N; i++)
			{
				if (color[i] == BLACK)
					solution.push_back(i);
			}
		}

		return;
	}
	
	bool isPossibleBlack = true;

	for (int i = 0; i < edge[n].size(); i++)
	{
		int dst = edge[n][i];

		if (color[dst] == BLACK)
		{
			isPossibleBlack = false;
			break;
		}
	}
	color[n] = WHITE;
	rec(n + 1);
	if (isPossibleBlack)
	{
		color[n] = BLACK;
		rec(n + 1);
	}
	color[n] = 0;
}
			

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> M;

	for (int m = 0; m < M; m++)
	{
		memset(color, 0, sizeof(color));
		maxBlack = 0;

		cin >> N >> K;
		
		for (int i = 1; i <= N; i++)
			edge[i].clear();

		for (int k = 0; k < K; k++)
		{
			int a, b;
			cin >> a >> b;
			
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		rec(1);
		

		cout << maxBlack << '\n';
		for (int i = 0; i < maxBlack; i++)
		{
			cout << solution[i];
			if(i+1 < maxBlack)
				cout << ' ';
		}
			 
		cout << '\n';
	}
	

	return 0;
}

