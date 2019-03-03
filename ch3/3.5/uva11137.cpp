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

const int MAX_N = 10000;

int N;
vector<LL> coins;


LL cache[MAX_N + 1];


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cache[0] = 1;

	for (int i = 1; i <= 21; i++)
	{
		coins.push_back(i*i*i);
	}

	for (int i = 0; i < coins.size(); i++)
	{
		for (int j = coins[i]; j <= MAX_N; j++)
		{
			cache[j] += cache[j - coins[i]];
		}
	}

	while (cin >> N)
	{
		cout << cache[N] << '\n';
	}
	



	return 0;
}

