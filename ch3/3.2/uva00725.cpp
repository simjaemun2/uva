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
const LL MAX_S1 = 9876543210;

int tc, TC;
LL N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		if (tc++)
			cout << '\n';

		int cnt = 0;
		int a;
		for (int f = 1234; (a = f * N)<= 98765; f++)
		{
			int used = (f < 10000);
			int t = f;
			
			while (t)
			{
				used |= 1 << (t % 10);
				t /= 10;
			}

			t = a;

			while (t)
			{
				used |= 1 << (t % 10);
				t /= 10;
			}

			if (used == (1 << 10) - 1)
			{
				cnt++;
				printf("%0.5d / %0.5d = %d\n", a, f, N);
			}
		}

		if (!cnt)
			cout << "There are no solutions for " << N << ".\n";
	}
	
	return 0;
}