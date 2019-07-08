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

const int MAX_D = 3;
const int MAX_DIAG = 8;
//            N   W  S  E
//            0   1  2  3
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1};
int DX[] = {  0, -1, 0, 1 , -1,1,-1,1};

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int N, K;

const int MAX_N = 75;
const int MAX_K = 5;

int input[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][MAX_K + 1][MAX_D];
bool visited[MAX_N][MAX_N][MAX_K + 1][MAX_D];

struct Node {
	int y, x, k, d;

	Node(int _y, int _x, int _k, int _d)
	{
		y = _y;
		x = _x;
		k = _k;
		d = _d;
	}
};

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	tc = 1;

	while (cin >> N >> K, N || K)
	{
		memset(visited, false, sizeof visited);

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				cin >> input[r][c];

				for (int k = 0; k <= K; k++)
				{
					for (int d = 0; d < MAX_D; d++)
					{
						cache[r][c][k][d] = -INF;
					}
				}
			}
		}

		const int LR = 1;
		const int RL = -1;
		const int D = 0;

		//d     -1 0 1
		//cache  0 1 2
		//dir    l d r
		queue<Node> q;
		q.push(Node(0, 0, input[0][0] < 0, D));

		cache[0][0][input[0][0] < 0][D + 1] = input[0][0];

		int answer = -INF;

		while (!q.empty())
		{
			Node cur = q.front();
			q.pop();

			visited[cur.y][cur.x][cur.k][cur.d + 1] = false;
			int s = cache[cur.y][cur.x][cur.k][cur.d + 1];

			if (cur.d != LR && 0 <= cur.x - 1)
			{
				int ny = cur.y;
				int nx = cur.x - 1;
				int nd = RL;
				int nk = (input[ny][nx] < 0) + cur.k;

				if (nk <= K
					&& cache[ny][nx][nk][nd + 1] < s + input[ny][nx])
				{
					cache[ny][nx][nk][nd + 1] = s + input[ny][nx];

					if (!visited[ny][nx][nk][nd + 1])
					{
						visited[ny][nx][nk][nd + 1] = true;
						q.push(Node(ny, nx, nk, nd));
					}
				}
			}
			
			if (cur.d != RL && cur.x + 1 < N)
			{
				int ny = cur.y;
				int nx = cur.x + 1;
				int nd = LR;
				int nk = (input[ny][nx] < 0) + cur.k;

				if (nk <= K
					&& cache[ny][nx][nk][nd + 1] < s + input[ny][nx])
				{
					cache[ny][nx][nk][nd + 1] = s + input[ny][nx];

					if (!visited[ny][nx][nk][nd + 1])
					{
						visited[ny][nx][nk][nd + 1] = true;
						q.push(Node(ny, nx, nk, nd));
					}
				}
			}

			if (cur.y + 1 < N)
			{
				int ny = cur.y + 1;
				int nx = cur.x;
				int nd = D;
				int nk = (input[ny][nx] < 0) + cur.k;

				if (nk <= K
					&& cache[ny][nx][nk][nd + 1] < s + input[ny][nx])
				{
					cache[ny][nx][nk][nd + 1] = s + input[ny][nx];

					if (!visited[ny][nx][nk][nd + 1])
					{
						visited[ny][nx][nk][nd + 1] = true;
						q.push(Node(ny, nx, nk, nd));
					}
				}
			}
		}

		
		for (int k = 0; k <= K; k++)
		{
			for (int d = 0; d < MAX_D; d++)
			{
				answer = max(answer, cache[N - 1][N - 1][k][d]);
			}
		}
		

		cout << "Case " << tc++ << ": ";

		if (answer == -INF)
			cout << "impossible\n";
		else
			cout << answer << '\n';

	}

	return 0;
}