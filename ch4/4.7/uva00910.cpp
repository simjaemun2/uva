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


int N, M;

const int MAX_N = 26;
const int MAX_M = 30;

int adj[MAX_N][2];
int cache[MAX_M + 1][MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	int tc = 1;

	while (cin >> N)
	{
		VI v;

		for (int n = 0; n < N; n++)
		{
			char a, b, c, d;
			cin >> a >> b >> c >> d;
			a -= 'A';
			b -= 'A';
			c -= 'A';
			adj[a][0] = b;
			adj[a][1] = c;

			if (d == 'x')
			{
				v.push_back(a);
			}
		}

		cin >> M;

		if (v.size())
		{
			memset(cache, 0, sizeof cache);

			cache[0][0] = 1;
			cache[1][adj[0][0]] = 1;
			cache[1][adj[0][1]]++;

			for (int m = 1; m < M; m++)
			{
				for (int n = 0; n < N; n++)
				{
					for (int d = 0; d < 2; d++)
					{
						cache[m + 1][adj[n][d]] += cache[m][n];
					}
				}
			}

			int answer = 0;
			for (int s : v)
			{
				answer += cache[M][s];
			}

			cout << answer << '\n';
		}
		else
		{
			cout << "0\n";
		}

		tc++;
	}

	return 0;
}