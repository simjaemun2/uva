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

#define MAX_N 30
#define MAX_VAL 3000

bool visited[MAX_N + 1][MAX_N + 1][MAX_VAL * 2 + 2];
int num[MAX_N + 1];
int sig[MAX_N + 1];

bool used[MAX_VAL * 2 + 2];

int N;

void dp(int idx, int open, int val)
{
	bool& v = visited[idx][open][val + 3000];

	if (v)
		return;

	v = true;

	if (idx == N)
	{
		used[val + 3000] = true;
		return;
	}

	int nval = val + num[idx] * sig[idx] * ((open % 2 == 0) ? 1 : -1);

	if (sig[idx] == -1)
		dp(idx + 1, open + 1, nval);
	if (open > 0)
		dp(idx + 1, open - 1, nval);
	dp(idx + 1, open, nval);
}

int main(int argc, char** argv)
{
	string line;
	while (getline(cin, line))
	{
		memset(visited, false, sizeof visited);
		memset(used, false, sizeof used);

		stringstream ss(line);
		string s;
		ss >> s;

		num[0] = stoi(s);
		sig[0] = 1;

		int index = 1;

		while (ss >> s)
		{
			if (s == "+")
				sig[index] = 1;
			else if (s == "-")
				sig[index] = -1;
			else
				num[index++] = stoi(s);
		}

		N = index;

		dp(0, 0, 0);

		int cnt = 0;

		for (int i = 0; i <= MAX_VAL * 2; i++)
		{
			if (used[i])
				cnt++;
		}

		cout << cnt << '\n';
	}
	
	return 0;
}