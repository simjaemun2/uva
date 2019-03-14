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
const int MAX_N = 20000;

int tc, TC;
int L, N;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);

	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> L >> N;

		int a;
		int minAnswer = 0;
		int maxAnswer = 0;

		for (int n = 0; n < N; n++)
		{
			cin >> a;
			a = min(a, L - a);
			minAnswer = max(minAnswer, a);
			maxAnswer = max(maxAnswer, L - a);
		}
		
		cout << minAnswer << ' ' << maxAnswer << '\n';

	}

	return 0;

}