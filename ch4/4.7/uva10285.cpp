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

int R,C;

const int MAX_RC = 100;

int board[MAX_RC][MAX_RC];
int cache[MAX_RC][MAX_RC];

int dp(int r, int c)
{
	int& ret = cache[r][c];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int d = 0; d < MAX_D; d++)
	{
		int nr = r + DY[d];
		int nc = c + DX[d];

		if (0 <= nr && nr < R
			&& 0 <= nc && nc < C
			&& board[r][c] > board[nr][nc])
		{
			ret = max(ret, dp(nr, nc) + 1);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		string name;
		cin >> name >> R >> C;
		
		memset(cache, -1, sizeof cache);

		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				cin >> board[r][c];
			}
		}

		int answer = 0;
		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				answer = max(answer, dp(r, c));
			}
		}

		cout << name << ": " << answer << '\n';
	}
	
	return 0;
}