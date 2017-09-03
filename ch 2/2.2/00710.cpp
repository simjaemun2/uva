#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;


#define MAX_WH 75

int W, H;
int X1, X2, Y1, Y2;

vector<bitset<MAX_WH + 2> > board;
vector<bitset<MAX_WH + 2> > bfsBoard;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node {
	int y, x, c, d;
};


int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int tc = 0;
	board = vector<bitset<MAX_WH + 2> >(MAX_WH + 2);
	while (cin >> W >> H)
	{
		tc++;

		if (W + H == 0)
			return 0;
		board[0].reset();
		board[H + 1].reset();

		cin.ignore();

		for (int y = 1; y <= H; y++)
		{
			board[y].reset();
			string line;
			getline(cin, line);
			for (int x = 1; x <= W; x++)
			{
				if (line[x-1] == 'X')
					board[y].set(x);
			}
		}

		printf("Board #%d:\n", tc);

		int p = 0;

		while (cin >> X1 >> Y1 >> X2 >> Y2)
		{
			if (X1 + X2 + Y1 + Y2 == 0)
				break;

			p++;
			bfsBoard.clear();
			bfsBoard.assign(board.begin(), board.begin() + H + 2);
			bfsBoard[Y1].reset(X1);
			bfsBoard[Y2].reset(X2);

			queue<Node> q;

			Node node;
			node.y = Y1;
			node.x = X1;
			node.c = 0;
			node.d = -1;
			q.push(node);

			int result = MAX_WH * MAX_WH * MAX_WH;

			while (!q.empty())
			{
				Node n = q.front();
				q.pop();
				bfsBoard[n.y].set(n.x);

				if (n.y == Y2 && n.x == X2 && result > n.c)
				{
					if(result > n.c)
						result = n.c;
					continue;
				}

				for (int d = 0; d < 4; d++)
				{
					int nx = n.x + dx[d];
					int ny = n.y + dy[d];

					if (0 <= nx && nx < W + 2
						&& 0 <= ny && ny < H + 2
						&& bfsBoard[ny].test(nx) == 0)
					{
						Node nextNode;
						nextNode.x = nx;
						nextNode.y = ny;
						nextNode.d = d;
						if (d == n.d)
							nextNode.c = n.c;
						else
							nextNode.c = n.c + 1;
						q.push(nextNode);
					}
				}
			}

			if (result < MAX_WH * MAX_WH * MAX_WH)
			{
				printf("Pair %d: %d segments.\n",p,result);
			}
			else
			{
				printf("Pair %d: impossible.\n", p);
			}
		}

		cout << '\n';
	}



	return 0;
}