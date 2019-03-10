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
const int MAX_M = 5000;

int tc, TC;
int N;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		vector<int> src(N), dst(N);

		for (int n = 0; n < N; n++)
		{
			cin >> src[n] >> dst[n];
		}

		if (N & 1)
		{
			cout << "NO\n";
			continue;
		}

		sort(src.begin(), src.end());
		sort(dst.begin(), dst.end());

		int i = 0;
		for (; i < N && src[i] == dst[i]; i++);

		if (i < N)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
	


	return 0;
}