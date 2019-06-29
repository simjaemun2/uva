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
#include <map>
#include <limits.h>
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;
typedef pair<int, PII> PPII;
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;
typedef vector<double > VD;
typedef vector<PII> VPII;
typedef vector<vector<PII> > VVPII;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
//            N   W  S  E
//            0   1  2  3
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1 };
int DX[] = { 0, -1, 0, 1 , -1,1,-1,1 };

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int N, M;

const int MAX_N = 15;

LL cache[MAX_N+1][MAX_N+1];
int input[MAX_N+1];
string line;

LL dp(int y, int x)
{
	if (y == N)
	{
		return 1LL;
	}

	LL& ret = cache[y][x];
	if (ret != -1LL)
		return ret;

	ret = 0LL;

	if (input[y + 1] == -1)
	{
		for (int nx = 1; nx <= N; nx++)
		{
			if (x - 1 > nx || nx > x + 1)
			{
				ret += dp(y + 1, nx);
			}
		}
	}
	else
	{
		for (int d = -1; d <= 1; d++)
		{
			int nx = x + d;
			
			if (1 <= nx && nx <= N && input[y + 1] == nx)
			{
				return ret;
			}
		}

		ret += dp(y + 1, input[y + 1]);
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> line)
	{
		N = line.size();
		
		for (int i = 0; i < N; i++)
		{
			if (line[i] == '?')
			{
				input[i+1] = -1;
			}
			else if ('1' <= line[i] && line[i] <= '9')
			{
				input[i+1] = line[i] - '0';
			}
			else
			{
				input[i+1] = line[i] - 'A' + 10;
			}
		}

		memset(cache, -1, sizeof cache);

		LL answer = 0LL;

		if (input[1] == -1)
		{
			for (int n = 1; n <= N; n++)
			{
				answer += dp(1, n);
			}
		}
		else
		{
			answer = dp(1, input[1]);
		}

		cout << answer << '\n';
	}


	return 0;
}