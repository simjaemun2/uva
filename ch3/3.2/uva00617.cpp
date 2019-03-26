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
const int MAX_N = 6;
const int MAX_SPEED = 60;

int tc, TC;
LL N;

double L[MAX_N], G[MAX_N], Y[MAX_N], R[MAX_N];
bool speed[MAX_SPEED + 2];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N != -1)
	{
		cout << "Case " << ++tc << ": ";

		for (int n = 0; n < N; n++)
		{
			cin >> L[n] >> G[n] >> Y[n] >> R[n];
		}

		for (int v = 30; v <= 60; v++)
		{		
			bool isPossible = true;

			for (int n = 0; n < N && isPossible; n++)
			{
				double t = L[n] * 3600 / v;
				double s = 0;
				
				while (s < t && isPossible)
				{
					s += G[n] + Y[n];
					
					if (s < t && t < s + R[n])
					{
						isPossible = false;
					}
					
 					s += R[n];
				}
			}

			speed[v] = isPossible;
		}

		int cnt;
		int first = 0;
		bool isFirst = true;

		for (int v = 30; v <= MAX_SPEED + 1; v++)
		{
			if (speed[v])
			{
				if (!first)
				{
					first = v;
					cnt = 1;
				}
				else
				{
					cnt++;
				}
			}
			else
			{
				if (first)
				{
					if (!isFirst)
					{
						cout << ", ";
					}

					isFirst = false;

					if (cnt == 1)
					{
						cout << first;
					}
					else
					{
						cout << first << '-' << first + cnt - 1;
					}

					first = 0;
				}
			}
		}

		if (isFirst)
		{
			cout << "No acceptable speeds.\n";
		}
		else
		{
			cout << '\n';
		}
	}
	
	return 0;
}