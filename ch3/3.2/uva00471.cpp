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

	cin >> TC;
	
	for (tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin >> N;

		for (int i = 1; i * N <= MAX_S1; i++)
		{
			LL s1 = i * N;
			
			int cnt[10] = { 0, };
			
			while (s1 > 0)
			{
				if (cnt[s1 % 10])
					break;
				cnt[s1 % 10]++;
				s1 /= 10;
			}

			int cnt2[10] = { 0, };
			int s2 = i;
			while (s2 > 0)
			{
				if (cnt2[s2 % 10])
					break;
				cnt2[s2 % 10]++;
				s2 /= 10;
			}

			if (!s1 && !s2)
			{
				cout << i * N << " / " << i << " = " << N << '\n';
			}
		}
	}
	
	return 0;
}