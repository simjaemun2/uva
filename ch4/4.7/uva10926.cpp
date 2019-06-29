﻿#define _CRT_SECURE_NO_WARNINGS 


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
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1};
int DX[] = {  0, -1, 0, 1 , -1,1,-1,1};

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int N;

const int MAX_N = 100;

int cache[MAX_N + 1];
int cnt[MAX_N + 1];

VVI adj;

int dp(int n)
{
	int& ret = cache[n];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int v : adj[n])
	{
		if (cache[v] == -1)
		{
			ret += dp(v);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	tc = 1;
	while (cin >> N, N)
	{
		memset(cnt, 0, sizeof cnt);
		adj = VVI(N + 1);

		for (int n = 1; n <= N; n++)
		{
			int t;
			cin >> t;
			while (t--)
			{
				int a;
				cin >> a;
				adj[n].push_back(a);
				cnt[a]++;
			}
		}

		int answer = 0;
		int answerIndex = 0;

		for (int n = 1; n <= N; n++)
		{
			if (!cnt[n])
			{
				memset(cache, -1, sizeof cache);

				if (answer < dp(n))
				{
					answer = dp(n);
					answerIndex = n;
				}
			}
		}

		cout << answerIndex << '\n';
	}
	
	return 0;
}