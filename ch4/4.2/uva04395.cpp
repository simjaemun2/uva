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

using namespace std;

#define MAX_N 100
#define MAX_D 4

int N, M;


vector<vector<int> > adj;
bool visited[MAX_N + 1];
int cnt[MAX_N + 1];

void dfs(vector<int>& answer, int n)
{
	visited[n] = true;

	for (int i : adj[n])
	{
		if (!visited[i])
			dfs(answer, i);
	}


	answer.push_back(n);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N >> M, N + M)
	{
		adj = vector<vector<int> >(N + 1);

		memset(visited, false, sizeof visited);
		memset(cnt, 0, sizeof cnt);

		for (int m = 0; m < M; m++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		vector<int> answer;

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
				dfs(answer, i);
		}

		cout << answer[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			cout << ' ' << answer[i];
		}
		cout << '\n';

	}
	return 0;
}
