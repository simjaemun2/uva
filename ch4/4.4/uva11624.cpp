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

int R, C;
const int MAX_D = 4;
int DY[] = { -1,1,0,0 };
int DX[] = { 0,0,-1,1 };

const int MAX_RC = 1000;
int board[MAX_RC][MAX_RC + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	cin >> TC;
	
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> R >> C;
		
		int sy=-1, sx;
		char ch;
		queue<PII > fq;

		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				cin >> ch;

				if (ch == 'J')
				{
					sy = r;
					sx = c;
					board[r][c] = -2;
				}
				else if (ch == 'F')
				{
					board[r][c] = 0;
					fq.push({ r,c });
				}
				else if (ch == '#')
				{
					board[r][c] = -2;
				}
				else // ch == '.'
				{
					board[r][c] = INF;
				}
			}
		}

		while (!fq.empty())
		{
			int cy = fq.front().first;
			int cx = fq.front().second;
			int step = board[cy][cx];
			fq.pop();

			for (int d = 0; d < MAX_D; d++)
			{
				int ny = cy + DY[d];
				int nx = cx + DX[d];

				if (0 <= ny && ny < R && 0 <= nx && nx < C
					&& board[ny][nx] == INF)
				{
					fq.push({ ny, nx });
					board[ny][nx] = step + 1;
				}
			}
		}
		
		int answer = -1;
		queue<pair<int, PII > > jq;
		jq.push({ 0, {sy, sx} });
		while (!jq.empty() && answer == -1)
		{
			int step = jq.front().first;
			int cy = jq.front().second.first;
			int cx = jq.front().second.second;
			jq.pop();

			for (int d = 0; d < MAX_D; d++)
			{
				int ny = cy + DY[d];
				int nx = cx + DX[d];

				if (0 <= ny && ny < R && 0 <= nx && nx < C)
				{
					if (step + 1 < board[ny][nx])
					{
						jq.push({ step + 1, {ny, nx} });
						board[ny][nx] = -2;
					}
				}
				else
				{
					answer = step + 1;
					break;
				}
			}
		}

		if (answer == -1)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << answer << '\n';
		}
	}

	return 0;
}