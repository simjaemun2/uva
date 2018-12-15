#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

#define LEN 8

int DAX[4] = { -1,1,0,0 };
int DAY[4] = { 0,0,-1,1 };

int DDX[4] = { -1,-1,1,1 };
int DDY[4] = { -1,1,-1,1 };

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int k, pq, nq;

	int kx, ky, pqx, pqy, nqx, nqy;

	string result;

	while (cin >> k >> pq >> nq)
	{
		if (k == pq)
		{
			cout << "Illegal state\n";
			continue;
		}
			
		
		ky = k / LEN;
		kx = k % LEN;
		pqy = pq / LEN;
		pqx = pq % LEN;
		nqy = nq / LEN;
		nqx = nq % LEN;


		//queen same position or diagonal move
		if ((pqx == nqx) == (pqy == nqy))
		{
			cout << "Illegal move\n";
			continue;
		}

		// queen can move
		
		if ((kx == pqx) && (pqx == nqx))// k, pq, nq are on the same Y-axis
		{
			if (pqy < nqy && pqy <= ky && ky <= nqy)
			{
				cout << "Illegal move\n";
				continue;
			}

			if (nqy < pqy && nqy <= ky && ky <= pqy)
			{
				cout << "Illegal move\n";
				continue;
			}
		}
		
		if((ky == pqy) && (pqy == nqy))// k, pq, nq are on the same X-axis
		{
			if (pqx < nqx && pqx <= kx && kx <= nqx)
			{
				cout << "Illegal move\n";
				continue;
			}

			if (nqx < pqx && nqx <= kx && kx <= pqx)
			{
				cout << "Illegal move\n";
				continue;
			}
		}
		
		int d;

		for (d = 0; d < 4; d++)
		{
			int dx = nqx + DAX[d];
			int dy = nqy + DAY[d];

			//move not allowed
			if (0 <= dx && dx < LEN && 0 <= dy && dy < LEN
				&& ((kx == dx) && (ky == dy)))
				break;
		}
			
		if (d < 4)
		{
			cout << "Move not allowed\n";
			continue;
		}

		for (d = 0; d < 4; d++)
		{
			int dx = kx + DDX[d];
			int dy = ky + DDY[d];

			//move not allowed
			if (0 > dx || dx >= LEN)
				continue;

			if (0 > dy || dy >= LEN)
				continue;

			if ((dx == nqx) && (dy == nqy))
				continue;

			break;
		}

		if (d == 4)
			cout << "Stop\n";
		else
			cout << "Continue\n";
		
	}

	return 0;
}
