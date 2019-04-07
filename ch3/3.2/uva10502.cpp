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

int tc, TC;
int R, C;

const int MAX_RC = 100;

char input[MAX_RC][MAX_RC + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> R, R)
	{
		cin >> C;

		int answer = 0;
		int t, w, len;

		for (int i = 0; i < R; i++)
		{
			cin >> input[i];
		}

		for (int i = 0; i < R; i++)
		{
			int sum[MAX_RC + 1] = { 0, };

			for (int j = i; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					sum[k] += input[j][k] - '0';

					if (k == 0 || t != w * len)
					{
						t = len = 0;
					}

					t += sum[k];
					len++;
					w = j - i + 1;

					if (t == w * len)
						answer += len;
				}
			}
		}

		cout << answer << '\n';
	}


	return 0;
}
