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


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;


const int INF = 2000000000;
const int MAX_RC = 51;
const int MAX_D = 4;

int tc, TC;
int N;
int R, C;
int cr, cc;
char cd;

string line;

bool grid[MAX_RC][MAX_RC];

int DR[MAX_D] = { -1,1,0,0 };
int DC[MAX_D] = { 0,0,-1,1 };

char D[128];
char LEFT[128];
char RIGHT[128];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> C >> R;
	
	D['N'] = 1;
	D['S'] = 0;
	D['W'] = 2;
	D['E'] = 3;

	LEFT['N'] = 'W';
	LEFT['W'] = 'S';
	LEFT['S'] = 'E';
	LEFT['E'] = 'N';

	RIGHT['N'] = 'E';
	RIGHT['E'] = 'S';
	RIGHT['S'] = 'W';
	RIGHT['W'] = 'N';

	while (cin >> cc >> cr >> cd)
	{
		cin >> line;

		bool lost = false;

		for (char c : line)
		{
			if (c == 'F')
			{
				int nr = cr + DR[D[cd]];
				int nc = cc + DC[D[cd]];

				if (0 <= nr && nr <= R && 0 <= nc && nc <= C)
				{
					cr = nr, cc = nc;
				}
				else
				{
					if (!grid[cr][cc])
					{
						grid[cr][cc] = true;
						lost = true;
						break;
					}
				}
			}
			else
			{
				cd = (c == 'L' ? LEFT[cd] : RIGHT[cd]);
			}
		}

		cout << cc << ' ' << cr << ' ' << cd;
		
		if (lost)
		{
			cout << " LOST";
		}
		
		cout << '\n';
	}
	
	return 0;
}


