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
int N,P,Q;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> P >> Q;

		vector<int> v(N);

		int gm = 0;
		int num = 0;
		int g;

		for (int n = 0; n < N; n++)
		{
			cin >> g;

			if (num < P && gm + g <= Q)
			{
				gm += g;
				num++;
			}
		}

		cout << "Case " << tc << ": " << num << '\n';
	}

	return 0;

}