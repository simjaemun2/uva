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

const int MAX_N = 40;
const int MAX_M = 10;
int N, M;

char input[MAX_N+1][MAX_N+1];
int indexArr[MAX_N + 1][MAX_N + 1];

int match[MAX_N * MAX_N];
bool visited[MAX_N * MAX_N];
VVI adj;
VI leftIndex;

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
		cin >> N >> M;

		adj.clear();
		leftIndex.clear();

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
			for (int m = 0; m < M; m++)
			{
				if (input[n][m] == '*')
				{
					indexArr[n][m] = adj.size();
					adj.push_back(VI());

					if ((n + m) % 2)
					{
						leftIndex.push_back(indexArr[n][m]);
					}

					if (0 < n && input[n - 1][m] == '*')
					{
						adj[indexArr[n - 1][m]].push_back(indexArr[n][m]);
						adj[indexArr[n][m]].push_back(indexArr[n-1][m]);
					}

					if (0 < m && input[n][m - 1] == '*')
					{
						adj[indexArr[n][m-1]].push_back(indexArr[n][m]);
						adj[indexArr[n][m]].push_back(indexArr[n][m-1]);
					}
				}
			}
		}

		memset(match, -1, sizeof match);
		int MCBM = 0;

		for(int leftNode: leftIndex)
		{
			memset(visited, false, sizeof visited);
			MCBM += Aug(leftNode);
		}
		cout << adj.size() - MCBM << '\n';
	}

	return 0;
}