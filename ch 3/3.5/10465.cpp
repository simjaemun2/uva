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
const int MAX_MNT = 10000;

int tc, TC;
int M,N,T;

int cache[MAX_MNT + 1];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> M >> N >> T)
	{
		memset(cache, -1, sizeof cache);

		int TT = T - min(N, M);

		cache[0] = 0;

		for (int t = 0; t <= TT; t++)
		{
			if (cache[t] != -1)
			{
				cache[t + N] = max(cache[t + N], cache[t] + 1);
				cache[t + M] = max(cache[t + M], cache[t] + 1);
			}
		}

		int t = T;
		while (cache[t] == -1)
			t--;

		if (t == T)
		{
			cout << cache[t] << '\n';
		}
		else
		{
			cout << cache[t] << ' ' << T - t << '\n';
		}
	}

	
	
	
	
	return 0;
}

