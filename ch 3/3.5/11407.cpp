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

using namespace std;

typedef long long int LL;
typedef pair<int, int > II;

const int INF = 2000000000;
const int MAX_N = 10000;

int tc, TC;
int N;
int cache[MAX_N + 1];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int i = 1; i <= MAX_N; i++)
	{
		cache[i] = i;
	}

	for (int i = 2; i <= 100; i++)
	{
		for (int j = i * i; j <= MAX_N; j++)
		{
			cache[j] = min(cache[j - i * i] + 1, cache[j]);
		}
	}


	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		cout << cache[N] << '\n';
	}
	
	
	return 0;
}

