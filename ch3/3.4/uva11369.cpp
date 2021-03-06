﻿#define _CRT_SECURE_NO_WARNINGS 

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

int TC;

int N;

int input[MAX_N];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	int tc;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		sort(input, input + N);

		int answer = 0;

		for (int i = N - 1; i >= 2; i -= 3)
		{
			answer += input[i - 2];
		}

		cout << answer << '\n';

	}
	
	return 0;
}