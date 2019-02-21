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

const int MAX_NUM = 30000;

double input;
vector<LL> coins = { 10000, 5000, 2000, 1000, 500
,200, 100, 50, 20, 10, 5 };

LL cache[MAX_NUM + 1];


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cache[0] = 1;

	for (int i = 0; i < coins.size(); i++)
	{
		for (int j = coins[i]; j <= MAX_NUM; j++)
		{
			cache[j] += cache[j - coins[i]];
		}
	}

	while (cin >> input, input > 0.0)
	{
		int num = (int)((input+1e-9) * 100);

		printf("%6.2lf%17lld\n", input, cache[num]);
	}


	return 0;
}

