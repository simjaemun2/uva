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
int cache[MAX_N + 1];
int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int i = 2; i <= MAX_N; i++)
	{
		cache[i] += cache[i - 1] + i;
	}

	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin >> N;

		int i = 3;
		
		for (; cache[i] < N; i++);

		int a = 0, b = 0;

		if (cache[i] - N == 1)
			a = 2, b = cache[i+1] - N - 2, i++;
		else
			a = cache[i] - N;

		bool isFirst = true;

		for (int j = 2; j <= i; j++)
		{
			if (j != a && j != b)
			{
				if (!isFirst)
					cout << ' ';
				cout << j;
				isFirst = false;
			}
		}
		cout << '\n';
	}
		
	return 0;

}