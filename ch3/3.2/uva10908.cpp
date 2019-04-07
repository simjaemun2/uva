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
int M,N,Q,R,C;

const int MAX_MN = 100;

char input[MAX_MN][MAX_MN + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> M >> N >> Q;
		cout << M << ' ' << N << ' ' << Q << '\n';
		for (int m = 0; m < M; m++)
			cin >> input[m];

		for (int q = 0; q < Q; q++)
		{
			cin >> R >> C;
			int d = 1;

			while (0 <= R - d && R + d < M && 0 <= C - d && C + d < N)
			{
				int i = -d;
				for (; i <= d; i++)
				{
					if (input[R - i][C - d] != input[R][C]
						|| input[R - i][C + d] != input[R][C]
						|| input[R - d][C - i] != input[R][C]
						|| input[R + d][C - i] != input[R][C])
					{
						break;
					}
				}

				if (i <= d)
					break;

				d++;
			}

			cout << 2 * (d - 1) + 1 << '\n';

		}

	}
	
	
	return 0;
}

