#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>
#include <math.h>
#include <functional>

using namespace std;

#define INF 987654321

#define MAX_N 10

int graph[MAX_N];
int dummy[MAX_N];

void push(int i, int j)
{
	dummy[i] ^= 1 << j;
	
	if (i > 0)
		dummy[i - 1] ^= 1 << j;
	
	if (j > 0)
		dummy[i] ^= 1 << (j - 1);
	
	if (i < MAX_N - 1)
		dummy[i + 1] ^= 1 << j;
	
	if (j < MAX_N - 1)
		dummy[i] ^= 1 << (j + 1);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	string name;

	while (getline(cin, name), name != "end")
	{
		for (int i = 0; i < MAX_N; i++)
		{
			graph[i] = 0;
			
			string line;
			
			getline(cin, line);
			
			for(int j = 0; j < MAX_N; j++)
			{			
				if (line[j] == 'O')
					graph[i] |= 1 << j;
			}
		}

		int minCnt = INF;

		for (int i = 0; i < (1 << MAX_N); i++)
		{
			for (int j = 0; j < MAX_N; j++)
				dummy[j] = graph[j];

			int cnt = 0;

			for (int j = 0; j < MAX_N; j++)
			{
				if (i & (1 << j))
				{
					cnt++;
					push(0, j);
				}
			}

			for (int j = 0; j < MAX_N - 1; j++)
			{
				for (int k = 0; k < MAX_N; k++)
				{
					if (dummy[j] & (1 << k))
					{
						cnt++;
						push(j + 1, k);
					}
				}
			}

			if (!dummy[MAX_N - 1])
				minCnt = min(minCnt, cnt);
		}

		cout << name << ' ';

		if (minCnt > 100)
			cout << -1 << '\n';
		else
			cout << minCnt << '\n';
	}

	return 0;
}