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
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};


const int MAX_RC = 200;

int R, C,M,N;
int board[MAX_RC + 1][MAX_RC + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	tc = 0;
	while (cin >> R >> C, R || C)
	{
		tc++;
		//cout << tc << '\n' << R << ' ' << C << '\n';
		memset(board, 0, sizeof board);

		cin >> M;
		
		for (int m = 0; m < M; m++)
		{
			int r, c;
			cin >> r >> c;
			board[r][c] = -1;
		}

		cin >> N;
		vector<pair<int, PII> > v;

		for (int n = 0; n < N; n++)
		{
			int y, x, r;
			cin >> y >> x >> r;

			v.push_back({ r*r, {y,x} });
		}

		for (int y = 1; y <= R; y++)
		{
			for (int x = 1; x <= C; x++)
			{
				if (!board[y][x])
				{
					for (auto p : v)
					{
						if ((y - p.second.first)*(y - p.second.first)
							+ (x - p.second.second)*(x - p.second.second) <= p.first)
						{
							board[y][x] = -1;
							break;
						}
					}
				}
			}
		}

		
		int answer = -1;

		if (!board[1][1])
		{
			queue<PII> q({ {1,1} });
			
			while (!q.empty())
			{
				int cy = q.front().first;
				int cx = q.front().second;
				q.pop();

				if (cy == R && cx == C)
				{
					answer = board[cy][cx];
					break;
				}

				for (int d = 0; d < MAX_D; d++)
				{
					int ny = cy + DY[d];
					int nx = cx + DX[d];

					if (1 <= ny && ny <= R && 1 <= nx && nx <= C
						&& board[ny][nx] == 0)
					{
						board[ny][nx] = board[cy][cx] + 1;

						q.push({ ny, nx });
					}
				}
			}
		}

		

		if (answer == -1)
		{
			cout << "Impossible.\n";
		}
		else
		{
			cout << answer << '\n';
		}
	}

	return 0;
}