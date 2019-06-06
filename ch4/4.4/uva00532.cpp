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
int DY[] = { -1,1,0,0,0,0,0};
int DX[] = { 0,0,-1,1,0,0};
int DZ[] = {0,0,0,0,-1,1};

const int MAX_D = 6;
const int MAX_LRC = 30;
int L,R,C;

char input[MAX_LRC+1][MAX_LRC+1][MAX_LRC+1];

struct Node {
	int x, y, z,s;
};


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	while (cin >> L >> R >> C, L || R || C)
	{
		Node startNode;
		startNode.s = 0;
		startNode.x = -1;
		for (int l= 0; l < L; l++)
		{
			for (int r = 0; r < R; r++)
			{
				cin >> input[l][r];
				for (int c = 0; c < C && startNode.x == -1; c++)
				{
					if (input[l][r][c] == 'S')
					{
						startNode.z = l;
						startNode.y = r;
						startNode.x = c;
						input[l][r][c] = '#';
					}
				}
			}
		}

		queue<Node> q;
		q.push(startNode);

		int answer = -1;

		while (!q.empty() && answer == -1)
		{
			Node cur = q.front();
			q.pop();

			for (int d = 0; d < MAX_D && answer == -1; d++)
			{
				int nz = DZ[d] + cur.z;
				int ny = DY[d] + cur.y;
				int nx = DX[d] + cur.x;

				if (0 <= nz && nz < L
					&& 0 <= ny && ny < R
					&& 0 <= nx && nx < C
					&& input[nz][ny][nx] != '#')
				{
					if (input[nz][ny][nx] == '.')
					{
						Node next;
						next.z = nz;
						next.y = ny;
						next.x = nx;
						next.s = cur.s + 1;
						input[nz][ny][nx] = '#';
						q.push(next);
					}
					else//E
					{
						answer = cur.s + 1;
					}
				}
			}
		}

		if (answer == -1)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in " << answer << " minute(s).\n";
		}
	}


	return 0;
}