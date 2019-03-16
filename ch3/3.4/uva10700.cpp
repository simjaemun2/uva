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
char input[10000];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	while (TC--)
	{
		cin >> input;
		int i = 0;
		LL res_max = 1LL, res_min = 0LL;
		LL acc_max = 0LL, acc_min = 1LL;
		LL num = 0;

		for (; input[i]; i++)
		{
			if (input[i] == '*')
			{
				acc_max += num;
				res_max *= acc_max;
				acc_max = 0LL;

				acc_min *= num;

				num = 0;
			}
			else if (input[i] == '+')
			{
				acc_max += num;

				acc_min *= num;
				res_min += acc_min;
				acc_min = 1LL;

				num = 0LL;
			}
			else
			{
				num = num * 10 + input[i] - '0';
			}
		}

		res_max *= acc_max + num;
		res_min += acc_min * num;

		cout << "The maximum and minimum are " << res_max << " and " << res_min << ".\n";
	}
		
	return 0;

}