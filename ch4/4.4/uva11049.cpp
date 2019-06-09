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


const int MAX_N = 6;
const char DIR[] = "NSWE#";

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	int sy, sx, ey, ex;

	while (cin >> sx >> sy, sy || sx)
	{
		cin >> ex >> ey;

		map<PII, set<PII> > m;

		for (int i = 0; i < 3; i++)
		{
			int x1, y1, x2, y2;

			cin >> x1 >> y1 >> x2 >> y2;

			//y1 == y2
			for (int x = x1 + 1; x <= x2; x++)
			{
				PII p1 = { y1, x };
				PII p2 = { y1 + 1, x };

				m[p2].insert(p1);
				m[p1].insert(p2);
			}

			//x1 == x2
			for (int y = y1 + 1; y <= y2; y++)
			{
				PII p1 = { y, x1 };
				PII p2 = { y, x1 + 1 };

				m[p2].insert(p1);
				m[p1].insert(p2);
			}
		}

		set<PII> s({ {sy, sx} });
		queue<pair<string, PII> > q;
		q.push({ "", {sy, sx } });
		
		while (!q.empty())
		{
			PII cp = q.front().second;
			int cy = q.front().second.first;
			int cx = q.front().second.second;
			string path = q.front().first;
			q.pop();

			if (cy == ey && cx == ex)
			{
				cout << path << '\n';
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int ny = cy + DY[d];
				int nx = cx + DX[d];
				PII np = { ny, nx };
				
				if ( 1 <= ny && ny <= MAX_N && 1 <= nx && nx <= MAX_N
					&& s.find(np) == s.end() && m[cp].find(np) == m[cp].end())
				{
					s.insert(np);
					q.push({ path + DIR[d], np });
				}
			}
		}


	}

	return 0;
}