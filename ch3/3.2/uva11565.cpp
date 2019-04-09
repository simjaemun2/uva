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
const int MAX_N = 100;

int tc, TC;
int A, B, C;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	
	while (TC--)
	{
		cin >> A >> B >> C;

		bool isPossible = false;

		if (A*A > C)//y,z pos
		{
			for (int x = 1; A - x >= 2 && x <= B && C - x * x >= 2 && !isPossible; x++)
			{
				if (B%x == 0)
				{
					for (int y = 1; A - x - y >= 1 && y <= B / x && C - x * x - y * y >= 1 && !isPossible; y++)
					{
						if (x!=y && (B / x) % y == 0)
						{
							int z = B / x / y;

							if (z!=x && z!=y && x + y + z == A && x*x + y * y + z * z == C)
							{
								isPossible = true;
								cout << x << ' ' << y << ' ' << z << '\n';
							}
						}
					}
				}
			}
		}
		else//y,z meg
		{
			for (int x = A + 2; x <= B && C - x * x >= 2 && !isPossible; x++)
			{
				if (B%x == 0)
				{
					for (int y = -B / x; y <= -1  && !isPossible; y++)
					{
						if ((B / x) % y == 0)
						{
							int z = B / x / y;
							
							if (z!=y && x + y + z == A && x*x + y * y + z * z == C)
							{
								isPossible = true;
								cout << y << ' ' << z << ' ' << x << '\n';
							}
						}
					}
				}
			}
		}

		if (!isPossible)
			cout << "No solution.\n";
	}
	

	return 0;
}
