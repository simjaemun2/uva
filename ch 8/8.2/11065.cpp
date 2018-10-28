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

#define MAX_I 60
#define MAX_R 3600

typedef long long int LL;

int N;
int I, R;

LL graph[MAX_I];

int cnt;
int maxSetNum;

void rec(int i, LL used, int depth)
{
	LL all = (1LL << I) - 1;

	if (used == all)
	{
		cnt++;
		maxSetNum = max(maxSetNum, depth);
	}
	else
	{
		for (int j = i; j < I; j++)
		{
			if (!(used & (1LL << j)))
				rec(j + 1, used | graph[j], depth + 1);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> N;

	while (N--)
	{
		
		cin >> I >> R;

		cnt = maxSetNum = 0;

		for (int i = 0; i < I; i++)
		{
			graph[i] = 1LL << i;
		}

		for (int i = 0; i < R; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a] |= 1LL << b;
			graph[b] |= 1LL << a;
		}

		rec(0, 0, 0);

		cout << cnt << '\n' << maxSetNum << '\n';
	}


	
	return 0;
}