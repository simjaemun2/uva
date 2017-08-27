#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int SZ, P;

#define MAX_D 4

int dx[MAX_D] = {0,-1,0,1};
int dy[MAX_D] = {1,0,-1,0};

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (cin >> SZ >> P)
	{
		if (SZ == 0)
			return 0;

		int y = SZ / 2 + 1;
		int x = SZ / 2 + 1;
		int cp = 1;
		int step = 1;
		int d = 0;

		while (cp + step < P)
		{
			cp += step;
			y += step * dy[d];
			x += step * dx[d];
			d = (d + 1) % MAX_D;
			if (d % 2 == 0)
				step++;
		}

		y += (P - cp) * dy[d];
		x += (P - cp) * dx[d];

		printf("Line = %d, column = %d.\n", y, x);
	}


	return 0;
}