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
const double INF = 9876543212345;


const int MAX_N = 50;
const int MAX_M = 1000;
const int MAX_P = 13;

int tc, TC;
int N, M, P;
LL dist[MAX_N + 1][MAX_N + 1];
pair<int, LL> operas[MAX_P + 1];

LL cache[MAX_P][1 << MAX_P];

int getDistance(int sx, int sy, int dx, int dy)
{
	return abs(sx - dx) + abs(sy - dy);
}

LL dp(int p, int mask, LL sum)
{
	if (mask == (1 << (P+1)))
	{
		return dist[operas[p].first][0];
	}

	LL& ret = cache[p][mask];

	if (ret != -1)
		return ret;

	ret = dist[operas[p].first][0] + sum;

	for (int np=1; np <= P; np++)
	{
		if (!((1 << np) & mask))
		{
			ret = min(ret,
				dp(np, (1 << np) | mask, sum - operas[np].second) + dist[operas[p].first][operas[np].first]
			);
		}
	}

	return ret;
}

void FW()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
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
		memset(dist, 0, sizeof dist);

		cin >> N >> M;

		N++;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dist[i][j] = INF;
			}
		}

		for (int m = 0; m < M; m++)
		{
			int a, b,c,d;
			scanf("%d %d %d.%d", &a, &b, &c, &d);
			
			dist[a][b] = min(dist[a][b], (LL)(c * 100 + d));
			dist[b][a] = min(dist[b][a], (LL)(c * 100 + d));
		}

		FW();

		cin >> P;
		
		LL sum = 0;
		for (int p = 1; p <= P; p++)
		{
			int c, d;

			scanf("%d %d.%d", &operas[p].first, &c, &d);

			operas[p].second = (LL)(c*100 + d);
			sum += operas[p].second;
		}

		LL answer = INF;
		memset(cache, -1, sizeof cache);

		dist[0][0] = 0;
		
		answer = min(answer, dp(0, 1, sum));

		if (sum <= answer)
		{
			cout << "Don't leave the house\n";
		}
		else
		{
			printf("Daniel can save $%.2lf\n", (double)(sum - answer) / 100.0);
		}
	}
	
	return 0;
}

