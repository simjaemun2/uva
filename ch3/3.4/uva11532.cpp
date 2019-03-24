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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_N = 1000;

int tc, TC;
int P, Q;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> P >> Q;

		ULL answer = 0LL;
		int acc = 0;

		while (P > 0 && Q > 0)
		{
			answer |= 1LL << acc;
			P--, Q--;
			acc += 2;

			if (P > 0)
			{
				answer |= 1LL << acc;
				P--;
				acc++;
			}
		}

		if (P > 0)
		{
			answer <<= P;
			answer |= (1LL << P) - 1LL;
		}

		cout << answer << '\n';
	}
		
	
	return 0;
}