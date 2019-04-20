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
const int MAX_RC = 10;
const int MAX_D = 4;

int tc, TC;
int N;
int R, C;
int cr, cc;
char cd;

string line;

int visited[MAX_RC][MAX_RC];
char grid[MAX_RC][MAX_RC+1];

int DR[MAX_D] = { -1,1,0,0 };
int DC[MAX_D] = { 0,0,-1,1 };

char D[128];

//char LEFT[128];
//char RIGHT[128];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	D['N'] = 0;
	D['S'] = 1;
	D['W'] = 2;
	D['E'] = 3;

	/*
	LEFT['N'] = 'W';
	LEFT['W'] = 'S';
	LEFT['S'] = 'E';
	LEFT['E'] = 'N';

	RIGHT['N'] = 'E';
	RIGHT['E'] = 'S';
	RIGHT['S'] = 'W';
	RIGHT['W'] = 'N';
	*/


	while (cin >> R >> C >> cc, R||C||cc)
	{
		memset(visited, -1, sizeof visited);

		for (int r = 0; r < R; r++)
			cin >> grid[r];

		cc--;
		cr = 0;
		visited[cr][cc] = 0;

		while (true)
		{
			int nr = cr + DR[D[grid[cr][cc]]];
			int nc = cc + DC[D[grid[cr][cc]]];

			if (0 <= nr && nr < R && 0 <= nc && nc < C)
			{
				if (visited[nr][nc] >= 0)//visited twice
				{
					cout << visited[nr][nc] << " step(s) before a loop of "
						<< (visited[cr][cc] - visited[nr][nc] + 1) << " step(s)\n";
					break;
				}
				else
				{
					visited[nr][nc] = visited[cr][cc] + 1;

					cr = nr;
					cc = nc;
				}
			}
			else
			{
				cout << visited[cr][cc] + 1 << " step(s) to exit\n";
				break;
			}
		}
	}
	
	
	return 0;
}


