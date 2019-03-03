#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>

using namespace std;

#define MAX_N 50000

int N;

int d[MAX_N + 1];
int cnt[MAX_N + 1];
bool visited[MAX_N + 1];

int dfs(int n)
{
	visited[n] = true;

	cnt[n] = 0;

	if (d[n] && !visited[d[n]])
	{
		cnt[n] += 1 + dfs(d[n]);
	}

	visited[n] = false;

	return cnt[n];
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		memset(d, 0, sizeof d);
		memset(visited, false, sizeof visited);
		memset(cnt, -1, sizeof cnt);

		for (int i = 1; i <= N; i++)
		{
			int a, b;
			cin >> a >> b;
			d[a] = b;
		}

		int answer = 0;
		int maxV = 0;

		for (int i = 1; i <= N; i++)
		{
			if (cnt[i] == -1)
				dfs(i);
			if (cnt[i] > maxV)
				maxV = cnt[i], answer = i;
		}

		cout << "Case " << tc << ": " << answer << '\n';
	}
	
	return 0;
}
