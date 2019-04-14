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
const int MAX_RC = 5;
const int MAX_D = 25;

int tc, TC;
int N;

struct People {
	int r, c, v;
};

People p[MAX_D];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	while (TC--)
	{
		cin >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> p[n].r >> p[n].c >> p[n].v;
		}

		int as = 1000000;
		int aa, bb, cc, dd, ee;

		for (int a = 0; a < MAX_D - 4; a++)
		{
			for (int b = a + 1; b < MAX_D - 3; b++)
			{
				for (int c = b + 1; c < MAX_D - 2; c++)
				{
					for (int d = c + 1; d < MAX_D - 1; d++)
					{
						for (int e = d + 1; e < MAX_D; e++)
						{
							int sum = 0;

							for (int n = 0; n < N; n++)
							{
								int minD = 10000;
								minD = min(minD, (abs(p[n].r - a / MAX_RC) + abs(p[n].c - a % MAX_RC))*p[n].v);
								minD = min(minD, (abs(p[n].r - b / MAX_RC) + abs(p[n].c - b % MAX_RC))*p[n].v);
								minD = min(minD, (abs(p[n].r - c / MAX_RC) + abs(p[n].c - c % MAX_RC))*p[n].v);
								minD = min(minD, (abs(p[n].r - d / MAX_RC) + abs(p[n].c - d % MAX_RC))*p[n].v);
								minD = min(minD, (abs(p[n].r - e / MAX_RC) + abs(p[n].c - e % MAX_RC))*p[n].v);
								sum += minD;
							}

							if (as > sum)
							{
								as = sum;
								aa = a, bb = b, cc = c, dd = d, ee = e;
							}
						}
					}
				}
			}
		}

		cout << aa << ' ' << bb << ' ' << cc << ' ' << dd << ' ' << ee << '\n';

	}

	

	return 0;
}
