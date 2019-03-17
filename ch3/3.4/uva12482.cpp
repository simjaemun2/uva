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
int N, L, C;



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> L >> C)
	{
		int line = 0;
		int cnt = 0;

		for (int n = 0; n < N; n++)
		{
			string s;
			cin >> s;

			if (cnt + s.length() <= C)
			{
				cnt += s.length() + 1;
			}
			else
			{
				cnt = s.length() + 1;
				line++;
			}
		}

		if (cnt > 0)
			line++;

		if (line % L)
			cout << line / L + 1 << '\n';
		else
			cout << line / L << '\n';

		
	}
		
	
	return 0;
}