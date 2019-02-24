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

const int INF = 987654321;
const int MAX_R = 1010;
const int MAX_C = 1010;

int tc, TC;

int cache[MAX_R+1][MAX_C+1];
string input[MAX_R + 1][MAX_C + 1];

int R, C;

int dp(int r, int c)
{
	int& ret = cache[r][c];

	if (ret != INF)
		return ret;

	ret = 0;

	int nc = 0;
	int nr = 0;

	for(int i=1; i<=input[r][c].size(); i++)
	{
		if (input[r][c][i] == '+' || i == input[r][c].size())
		{
			ret += dp(nr, nc);
			nr = nc = 0;
		}
		else
		{
			if ('A' <= input[r][c][i] && input[r][c][i] <= 'Z')
			{
				nc = nc * 26 + input[r][c][i] - 'A' + 1;
			}
			else
			{
				nr = nr * 10 + input[r][c][i] - '0';
			}
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
		cin >> C >> R;

		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				cin >> input[r][c];
				
				cache[r][c] = INF;

				if (input[r][c][0] != '=')
				{
					cache[r][c] = stoi(input[r][c]);
				}
			}
		}
		
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				dp(r, c);
			}
		}

		for (int r = 1; r <= R; r++)
		{
			cout << cache[r][1];

			for (int c = 2; c <= C; c++)
			{
				cout << ' ' << cache[r][c];
			}
			cout << '\n';
		}
		
	}
	
	
	return 0;
}

