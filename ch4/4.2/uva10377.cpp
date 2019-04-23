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


const int INF = 987654321;
const int SZ_RC = 60;
const int SZ_D = 4;

int tc, TC;
int R,C;

string grid[SZ_RC];
int DY[SZ_D] = { -1,1,0,0 };
int DX[SZ_D] = { 0,0,-1,1 };
char RIGHT[SZ_D] = { 'E','W','N','S' };
char LEFT[SZ_D] = { 'W','E','S','N' };
int D[128];
string dir = "NSWE";

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	D['N'] = 0;
	D['S'] = 1;
	D['W'] = 2;
	D['E'] = 3;

	string line;
	getline(cin, line);

	TC = stoi(line);
	
	while (TC--)
	{
		getline(cin, line);
		getline(cin, line);

		istringstream iss(line);

		iss >> R >> C;

		for (int r = 0; r < R; r++)
		{
			getline(cin, grid[r]);
		}

		getline(cin, line);
		iss = istringstream(line);

		int cr, cc;
		iss >> cr >> cc;
		cr--, cc--;
		int d = 0;

		bool isEnd = false;

		while (!isEnd)
		{
			getline(cin, line);

			for (char c : line)
			{
				if (c == 'Q')
				{
					isEnd = true;
				}
				else if (c == 'R')
				{
					d = D[RIGHT[d]];
				}
				else if (c == 'L')
				{
					d = D[LEFT[d]];
				}
				else if (c == 'F')
				{
					int nr = cr + DY[d];
					int nc = cc + DX[d];

					if (0 <= nr && nr < R
						&& 0 <= nc && nc < C
						&& grid[nr][nc] == ' ')
					{
						cr = nr, cc = nc;
					}
				}
			}
		}

		cout << cr+1 << ' ' << cc+1 << ' ' << dir[d] << '\n';

		if (TC)
			cout << '\n';
	}
	

	
	return 0;
}

