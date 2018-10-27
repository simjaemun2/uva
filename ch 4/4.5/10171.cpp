#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>
#include <math.h>
#include <functional>

using namespace std;

#define INF 987654321

#define MAX_AB 26

int N;

int graphY[MAX_AB + 1][MAX_AB + 1];
int graphM[MAX_AB + 1][MAX_AB + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		for (int i = 0; i < MAX_AB; i++)
		{
			for (int j = 0; j < MAX_AB; j++)
			{
				graphY[i][j] = INF;
				graphM[i][j] = INF;
			}

			graphY[i][i] = graphM[i][i] = 0;
		}

		while (N--)
		{
			char YM, UB, X, Y;
			int C;

			cin >> YM >> UB >> X >> Y >> C;

			if (YM == 'Y')
			{
				graphY[X - 'A'][Y - 'A'] = min(C, graphY[X - 'A'][Y - 'A']);
				if(UB == 'B')
					graphY[Y - 'A'][X - 'A'] = min(C, graphY[Y - 'A'][X - 'A']);
			}
			else
			{
				graphM[X - 'A'][Y - 'A'] = min(C, graphM[X - 'A'][Y - 'A']);
				if (UB == 'B')
					graphM[Y - 'A'][X - 'A'] = min(C, graphM[Y - 'A'][X - 'A']);
			}
		}

		int length = INF;

		char A, B;
		cin >> A >> B;

		for (int k = 0; k < MAX_AB; k++)
		{
			for (int i = 0; i < MAX_AB; i++)
			{
				for (int j = 0; j < MAX_AB; j++)
				{
					graphM[i][j] = min(graphM[i][j], graphM[i][k] + graphM[k][j]);
					graphY[i][j] = min(graphY[i][j], graphY[i][k] + graphY[k][j]);
				}
			}
		}

		for (int i = 0; i < MAX_AB; i++)
		{
			if (graphY[A - 'A'][i] + graphM[B - 'A'][i] < length)
			{
				length = graphY[A - 'A'][i] + graphM[B - 'A'][i];
			}
		}

		if (length == INF)
			cout << "You will never meet.\n";
		else
		{
			cout << length;

			for (int i = 0; i < MAX_AB; i++)
			{
				if (graphY[A - 'A'][i] + graphM[B - 'A'][i] == length)
				{
					cout << ' ' << (char)(i + 'A');
				}
			}

			cout << '\n';
		}
			
	}
	
	

	return 0;
}