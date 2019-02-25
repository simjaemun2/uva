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
const int MAX_N = 100;
const int MAX_VAL = 32000;

int tc, TC;
int N, S;

int input[MAX_N];
int answer;
int cache[MAX_VAL * 2 + 10][MAX_N + 10];
char parents[MAX_VAL * 2 + 10][MAX_N + 10];

int dp(int res, int n)
{
	if (n == N)
	{
		if (res == answer)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int& ret = cache[res + MAX_VAL][n];
	char& parent = parents[res + MAX_VAL][n];


	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	if (res + input[n] <= MAX_VAL)
	{
		int ret = dp(res + input[n], n + 1);
		if (ret == 1)
		{
			parent = '+';
			return ret;
		}
	}

	if (res - input[n] >= -MAX_VAL)
	{
		int ret = dp(res - input[n], n + 1);
		if (ret == 1)
		{
			parent = '-';
			return ret;
		}
	}

	if (-MAX_VAL <= res * input[n] && res * input[n] <= MAX_VAL)
	{
		int ret = dp(res * input[n], n + 1);
		if (ret == 1)
		{
			parent = '*';
			return ret;
		}
	}

	if (res % input[n] == 0)
	{
		int ret = dp(res / input[n], n + 1);
		if (ret == 1)
		{
			parent = '/';
			return ret;
		}
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
		cin >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		memset(cache, -1, sizeof cache);

		cin >> answer;

		int a = dp(input[0], 1);

		if (a)
		{
			cout << input[0];

			int res = input[0];

			for (int i = 1; i < N; i++)
			{
				cout << parents[res + MAX_VAL][i] << input[i];

				if (parents[res + MAX_VAL][i] == '+')
				{
					res += input[i];
				}
				else if (parents[res + MAX_VAL][i] == '-')
				{
					res -= input[i];
				}
				else if (parents[res + MAX_VAL][i] == '*')
				{
					res *= input[i];
				}
				else if (parents[res + MAX_VAL][i] == '/')
				{
					res /= input[i];
				}
			}
			cout << '=' << answer << '\n';

		}
		else
		{
			cout << "NO EXPRESSION\n";
		}
	}
	
	
	return 0;
}

