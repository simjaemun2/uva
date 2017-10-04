#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 10000

int N, M, T, itime;
string bank;
int arrival[MAX_N];
int result[MAX_N];

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	
	for (int t = 0; t < tc; t++)
	{
		if(t != 0)
			cout << '\n';

		queue<int > q[2];

		cin >> N >> T >> M;

		for (int m = 0; m < M; m++)
		{
			cin >> arrival[m] >> bank;
			if (bank[0] == 'l')
				q[0].push(m);
			else
				q[1].push(m);
		}

		int curTime = 0;
		int curBank = 0;

		while (!q[0].empty() || !q[1].empty())
		{
			int next = -1;
			if (q[1].empty())
				next = arrival[q[0].front()];
			else if (q[0].empty())
				next = arrival[q[1].front()];
			else
				next = min(arrival[q[0].front()], arrival[q[1].front()]);
			curTime = max(next, curTime);

			int n = 0;
			while (!q[curBank].empty() && arrival[q[curBank].front()] <= curTime && n < N)
			{
				result[q[curBank].front()] = curTime + T;
				q[curBank].pop();
				n++;
			}

			curTime += T;
			curBank = (curBank + 1) % 2;
		}

		for (int i = 0; i < M; i++)
			cout << result[i] << '\n';
	}
	
	return 0;
}