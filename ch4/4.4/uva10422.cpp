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
//int DY[] = { -1,0,1,0,-1,-1,1,1 };
//int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 5;
int N, M;

string FINAL = "111110111100 110000100000";

struct Node {
	int d;
	int y;
	int x;
	string board;
};
const int MAX_D = 8;
int DY[MAX_D] = { -1, -2, -2, -1, 1, 2,  2,  1 };
int DX[MAX_D] = { -2, -1,  1,  2, 2, 1, -1, -2 };


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	string line;
	getline(cin, line);
	TC = stoi(line);
	//tc = 1;
	
	//while (cin >> N)

	//cin >> TC;
	for(tc=1; tc<=TC; tc++)
	{
		Node node;
		node.d = 0;
		node.y = -1;
		node.board = "";

		for (int n = 0; n < MAX_N; n++)
		{
			getline(cin, line);
			for (int i = 0; i < MAX_N && node.y == -1; i++)
			{
				if (line[i] == ' ')
				{
					node.y = n;
					node.x = i;
				}
			}
			node.board += line;
		}
		//node.board = FINAL;
		queue<Node > q;
		set<string > s;
		
		q.push(node);
		s.insert(node.board);

		while (!q.empty())
		{
			Node cur = q.front();
			q.pop();

			if (cur.d > 10)
			{
				cout << "Unsolvable in less than 11 move(s).\n";
				break;
			}

			if (!FINAL.compare(cur.board))
			{
				cout << "Solvable in " << cur.d << " move(s).\n";
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int nextY = cur.y + DY[d];
				int nextX = cur.x + DX[d];

				if (0 <= nextY && nextY < MAX_N
					&& 0 <= nextX && nextX < MAX_N)
				{
					string nextBoard = cur.board;
					char t = nextBoard[MAX_N*nextY + nextX];
					nextBoard[MAX_N*nextY + nextX] = ' ';
					nextBoard[MAX_N*cur.y + cur.x] = t;
					
					if (s.find(nextBoard) == s.end())
					{
						s.insert(nextBoard);

						Node nextNode;
						nextNode.y = nextY;
						nextNode.x = nextX;
						nextNode.board = nextBoard;
						nextNode.d = cur.d + 1;

						q.push(nextNode);
					}
				}
			}
		}
	}


	return 0;
}