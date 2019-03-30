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
const int MAX_N = 10000;

int tc, TC;
int N;
string s;
int input[MAX_N + 1];
int index[MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (cin >> s, s.back() != '0')
	{
		N = stoi(s.substr(0, s.length() - 1));

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
			index[input[n]] = n;
		}

		bool isPossible = true;

		for (int i = 0; i < N - 2 && isPossible; i++)
		{
			for (int j = i + 1; j < N - 1 && isPossible; j++)
			{
				int k = 2 * input[j] - input[i];
				
				if (0 <= k && k < N)
				{
					if (index[k] > j)
					{
						isPossible = false;
						break;
					}
				}
				
			}
		}

		cout << (isPossible ? "yes\n" : "no\n");
	}

	
	
	return 0;
}