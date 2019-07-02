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
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1};
int DX[] = {  0, -1, 0, 1 , -1,1,-1,1};

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

const int MAX_N = 10;
const int MAX_K = 1000;

int N,K,D;

int adj[MAX_N + 1][MAX_N + 1][MAX_K + 1];
int cache[MAX_N + 1][MAX_K + 1];

int dp(int n, int k)
{
	if (k == K)
	{
		return n == N ? 0 : INF;
	}

	int& ret = cache[n][k];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int nn = 1; nn <= N; nn++)
	{
		if (nn != n && adj[n][nn][k])
		{
			ret = min(ret, dp(nn, k + 1) + adj[n][nn][k]);
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
	while (cin >> N >> K, N || K)
	{

		memset(cache, -1, sizeof cache);

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i != j)
				{
					cin >> D;
					for (int d = 0; d < D; d++)
					{
						cin >> adj[i][j][d];
					}
					for (int d = D; d < K; d++)
					{
						adj[i][j][d] = adj[i][j][d - D];
					}
				}
			}
		}

		int answer = dp(1, 0);

		cout << "Scenario #" << tc++ << '\n';

		if (answer == INF)
		{
			cout << "No flight possible.\n\n";
		}
		else
		{
			cout << "The best flight costs " << answer << ".\n\n";
		}
	}
	
	return 0;
}