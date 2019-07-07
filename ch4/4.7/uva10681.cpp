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

const int MAX_N = 100;

bool A[MAX_N][MAX_N];
bool B[MAX_N][MAX_N];
bool T[MAX_N][MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> N >> M , N || M)
	{
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);

		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			B[u][v] = B[v][u] = true;
		}

		int S, E, D;
		cin >> S >> E >> D;

		for (int i = 0; i < N; i++)
		{
			A[i][i] = true;
		}

		while (D)
		{
			if (D & 1)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						T[i][j] = false;
						for (int k = 0; k < N; k++)
						{
							T[i][j] |= A[i][k] & B[k][j];
						}
					}
				}
				
				memcpy(A, T, sizeof A);
			}

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					T[i][j] = false;
					for (int k = 0; k < N; k++)
					{
						T[i][j] |= B[i][k] & B[k][j];
					}
				}
			}

			memcpy(B, T, sizeof B);
			D >>= 1;
		}

		if (A[S - 1][E - 1])
		{
			cout << "Yes, Teobaldo can travel.\n";
		}
		else
		{
			cout << "No, Teobaldo can not travel.\n";
		}
	}

	return 0;
}