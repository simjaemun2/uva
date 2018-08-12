#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAX_N 100
#define MAX_COST 10000
#define INF 9999999
int N;
int P;

int input[MAX_N + 1];
int cache[MAX_COST * 2];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> P >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		memset(cache, INF, sizeof(cache));

		cache[0] = 0;

		for (int n = 0; n < N; n++)
		{
			for (int p = P; p >= 0; p--)
			{
				cache[p + input[n]] = min(cache[p + input[n]], cache[p] + 1);
			}
		}

		for (int p = P; p <= INF; p++)
		{
			if (cache[p] < INF && cache[p])
			{
				cout << p << ' ' << cache[p] << '\n';
				break;
			}
		}
	}


	


	return 0;
}

