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

#define MAX_N 15

int N;

int col[MAX_N];
int ans, OK;


void backtrack(int rw, int ld, int rd, int c)
{
	if (rw == OK)
		ans++;

	int pos = OK & (~(rw | ld | rd)) & ~col[c];

	while (pos)
	{
		int p = pos & -pos;
		pos -= p;
		backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1, c + 1);
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> N, N)
	{
		ans = 0;
		OK = (1 << N) - 1;

		for (int i = 0; i < N; i++)
			col[i] = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				char c;
				cin >> c;
				if (c == '*')
					col[j] |= 1 << i;
			}
		}

		backtrack(0, 0, 0, 0);

		cout << "Case " << tc++ << ": " << ans << '\n';
	}

	return 0;
}