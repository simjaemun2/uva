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

int N, M, K;
const int MAX_N = 60;
const int MAX_K = 16;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> N >> M >> K, N || M || K)
	{
		VVI adj(N);

		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		queue<PII> q;
		q.push({ 1, 0 });

		int answer = -1;

		while (!q.empty())
		{
			int cur = q.front().second;
			int step = q.front().first;
			q.pop();

			if (cur == N - 1 && step >= K)
			{
				answer = step;
				break;
			}

			if (step == 20)
			{
				break;
			}

			for (int next : adj[cur])
			{
				q.push({ step + 1, next });
			}
		}

		if (answer == -1)
		{
			cout << "LOSER\n";
		}
		else
		{
			cout << answer << '\n';
		}
	}

	return 0;
}