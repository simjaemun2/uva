#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > II;

const int INF = 2000000000;
const int MAX_N = 1000;

int N,M;
int input[MAX_N + 1];
LL cache[MAX_N + 1][MAX_N + 1];


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int n = 0; n <= MAX_N; n++)
	{
		cache[n][0] = 1;
	}

	while (cin >> N >> M, N)
	{
		for (int n = 1; n <= N; n++)
		{
			cin >> input[n];
		}

		LL answer = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cache[i][j] = (cache[i - 1][j] + cache[i - 1][j - 1] * input[i]) % M;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			answer = max(answer, cache[N][i]);
		}

		cout << answer << '\n';
	}

	

	return 0;
}

