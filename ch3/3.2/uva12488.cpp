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
#include <limits.h>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_N = 24;

int tc, TC;
int N;
string s;
int input[MAX_N + 1];
int idx[MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (cin >> N)
	{
		for (int n = 1; n <= N; n++)
		{
			cin >> input[n];
			idx[input[n]] = n;
		}

		for (int n = 1; n <= N; n++)
		{
			cin >> input[n];
		}

		int cnt = 0;

		for (int i = 1; i <= N - 1; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (idx[input[i]] > idx[input[j]])
				{
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		
	}

	
	
	return 0;
}