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
unsigned int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		int answer = 0;

		while (N > 0)
		{
			if (N & 1)
			{
				if (N > 3 && (N & 3) == 3)
				{
					N++;
				}
				else
				{
					N--;
				}
			}
			else
			{
				N >>= 1;
			}

			answer++;
		}

		cout << answer << '\n';
	}
		
	
	return 0;
}