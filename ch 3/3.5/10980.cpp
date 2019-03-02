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
typedef unsigned long long int ULL;
typedef pair<int, int > II;

const int INF = 2000000000;
const int MAX_N = 100;
const int MAX_M = 20;
const int MAX_K = 100;

int tc;

int M;
double unit;
string line;

int N[MAX_M+1];
double P[MAX_M+1];
int K[MAX_K+1];

double cache[MAX_K+1];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (getline(cin, line))
	{
		cout << "Case " << ++tc << ":\n";

		istringstream(line) >> P[0] >> M;

		for (int m = 1; m <= M; m++)
		{
			getline(cin, line);
			istringstream(line) >> N[m] >> P[m];
		}

		getline(cin, line);
		istringstream iss(line);
		int nk = 0;
		int max_k = 0;

		
		while (iss >> K[nk])
		{
			max_k = max(max_k, K[nk++]);
		}

		for (int k = 1; k <= max_k; k++)
		{
			cache[k] = P[0] * k;
		}

		for (int i = 1; i <= M; i++)
		{
			for (int k = 1; k < N[i]; k++)
			{
				cache[k] = min(cache[k], P[i]);
			}

			for (int k = N[i]; k <= max_k; k++)
			{
				cache[k] = min(cache[k], cache[k - N[i]] + P[i]);
			}
		}

		for (int k = 0; k < nk; k++)
		{
			printf("Buy %d for $%.2f\n", K[k], cache[K[k]]);
		}
	}

	

	return 0;
}

