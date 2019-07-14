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

const int MAX_NM = 100;
int N, M;
int match[MAX_NM * 2];
bool visited[MAX_NM];
int VN[MAX_NM], VM[MAX_NM];
VVI adj;

int Aug(int u)
{
	if (visited[u])
		return 0;
	visited[u] = true;

	for (int v : adj[u])
	{
		if (match[v] == -1 || Aug(match[v]))
		{
			match[v] = u;
			return 1;
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			cin >> VN[n];
		}

		cin >> M;

		adj = VVI(N + M);

		for (int m = 0; m < M; m++)
		{
			cin >> VM[m];
		}

		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (VN[n] != 0 && (VM[m] == 0 || VM[m] % VN[n] == 0))
				{
					adj[n].push_back(N + m);
				}
				else if (VN[n] == 0 && VM[m] == 0)
				{
					adj[n].push_back(N + m);
				}
			}
		}

		memset(match, -1, sizeof match);
		
		int MCBM = 0;

		for (int n = 0; n < N; n++)
		{
			memset(visited, false, sizeof visited);
			MCBM += Aug(n);
		}

		cout << "Case " << tc << ": " << MCBM << '\n';
	}

	return 0;
}