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

int N;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> N)
	{
		LL a;
		cin >> a;

		LL localMax = a;
		LL localMin = a;
		LL answer = a;

		for (int i = 1; i < N; i++)
		{
			cin >> a;

			if (a > 0)
			{
				localMax = max(localMax*a, a);
				localMin = min(localMin*a, a);
			}
			else
			{
				LL t = max(localMin * a, a);
				localMin = min(a, localMax*a);
				localMax = t;
			}

			answer = max(answer, localMax);
		}

		if (answer < 0)
			answer = 0LL;

		cout << "Case #" << tc++ << ": The maximum product is " << answer << ".\n\n";
	}
	
	return 0;
}

