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
typedef pair<int, int > II;

const int INF = 2000000000;


const int MAX_M = 10;
const int MAX_N = 100;
const int MAX_D = 3;
int tc, TC;
int N, M;
int graph[MAX_M + 1][MAX_N + 1];
int D[] = {-1,0,1};
int cache[MAX_M+1][MAX_N+1];

int dp(int m, int n)
{
	if (n == N)
		return 0;

	int& ret = cache[m][n];

	if (ret != INF)
		return ret;

	for (int d = 0; d < MAX_D; d++)
	{
		int nextM = (m + D[d] + M) % M;

		ret = min(ret, dp(nextM, n + 1));
	}

	ret += graph[m][n];

	return ret;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> M >> N)
	{
		for (int m = 0; m < M; m++)
		{
			for (int n = 0; n < N; n++)
			{
				cin >> graph[m][n];
				cache[m][n] = INF;
			}
		}

		int answer = INF;
		int am;
		for (int m = 0; m < M; m++)
		{
			if (answer > dp(m, 0))
			{
				answer = dp(m, 0);
				am = m;
			}
		}

		int a = answer - graph[am][0];

		vector<int> path(1, am + 1);

		for (int n = 1; n < N; n++)
		{
			int cand = M;

			for (int d = 0; d < MAX_D; d++)
			{
				int nextM = (am + D[d] + M) % M;

				if (a == cache[nextM][n])
				{
					if (cand > nextM)
					{
						cand = nextM;
					}
				}
			}

			a -= graph[cand][n];
			path.push_back(cand + 1);
			am = cand;
		}

		for (int n = 0; n < N; n++)
		{
			cout << path[n];
			
			if(n < N-1)
				cout << ' ';
		}

		cout << '\n' << answer << '\n';
	}
	
	return 0;
}

