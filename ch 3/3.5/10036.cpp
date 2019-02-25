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
const int MAX_N = 100000;
const int MAX_K = 100;

int tc, TC;
int N,K;
vector<int> v;
bool cache[MAX_N + 1][MAX_K + 1];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> K;

		v.clear();

		for (int n = 0; n < N; n++)
		{
			int a;

			cin >> a;
			a %= K;
			if (a < 0)
			{
				a += K;
			}

			if (a > 0)
			{
				v.push_back(a);
			}
		}

		if (!v.size())
		{
			cout << "Divisible\n";
			continue;
		}

		N = v.size();

		memset(cache, false, sizeof cache);

		cache[0][0] = true;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K; j++)
			{
				int k = (j + v[i]) % K;
				cache[i + 1][k] |= cache[i][j];
				
				k = (j - v[i] + K) % K;
				cache[i + 1][k] |= cache[i][j];
			}
		}

		cout << (cache[N][0] ? "Divisible\n" : "Not divisible\n");
	}
	
	
	
	return 0;
}

