#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

#define MAX_N 1000

int N, M;

struct Coord {
	int line;
	int index;
};

Coord getCoord(int n)
{
	Coord c;
	c.line = floor(sqrt(n));
	c.index = n - c.line * c.line;
	return c;
}

double getX(Coord c)
{
	return 0.5 * (c.index - c.line);
}

double getY(Coord c)
{
	return c.line * sqrt(3) / 2.0 + (c.index % 2 == 1 ? sqrt(3)/6.0 : sqrt(3)/3.0);
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (scanf("%d %d",&N, &M) != -1)
	{
		Coord cn = getCoord(N);
		Coord cm = getCoord(M);
		
		double cnx = getX(cn);
		double cny = getY(cn);
	
		double cmx = getX(cm);
		double cmy = getY(cm);

		double dx = cnx - cmx;
		double dy = cny - cmy;

		/*
		printf("cn.line : %d, cn.index : %d\n", cn.line, cn.index);
		printf("cm.line : %d, cm.index : %d\n", cm.line, cm.index);
		printf("cnx : %lf, cny : %lf\n", cnx, cny);
		printf("cmx : %lf, cmy : %lf\n", cmx, cmy);
		*/
		printf("%.3lf\n", sqrt(dx*dx + dy*dy));
	}
	
	return 0;
}

