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
const int MAX_M = 200;
const int MAX_C = 20;


int tc, TC;
int M,C,K;
vector<int> garments[MAX_C];


int cache[MAX_M+1][MAX_C+1];

int dp(int m, int c)
{
	if (m < 0)
	{
		return -INF;
	}

	if (c == C)
	{
		return M - m;
	}

	int& ret = cache[m][c];

	if (ret != -1)
		return ret;

	ret = -INF;

	for (int g: garments[c])
	{
		ret = max(ret, dp(m - g, c + 1));
	}

	return ret;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> M >> C;
		
		memset(cache, -1, sizeof cache);

		for (int c = 0; c < C; c++)
		{
			cin >> K;
			garments[c] = vector<int>(K);

			for (int k = 0; k < K; k++)
			{
				cin >> garments[c][k];
			}
		}

		int answer = dp(M, 0);

		if (answer >= 0)
			cout << answer << '\n';
		else
			cout << "no solution\n";

	}

	
	
	
	
	return 0;
}

