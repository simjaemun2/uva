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
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 987654321;
const int MAX_N = 100;
const int MAX_D = 4;


int tc, TC;
int N;
int grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	tc = 1;
	while (cin >> N, N)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < N; m++)
			{
				cin >> grid[n][m];
			}
		}


		cout << "Case " << tc++ << ':';

		if (N % 2==0)
		{
			for (int n = N - 1, i = 0; n >= 1; n -= 2, i++)
			{
				int sum = 0;
				for (int j = 0; j < n; j++)
				{
					sum += grid[i][i + j] + grid[i + j][N - 1 - i]
						+ grid[N - 1 - i][N - 1 - j - i] + grid[N - 1 - j - i][i];
				}
				cout << ' ' << sum;
			}
		}
		else
		{
			for (int n = N - 1,i = 0; n > 1; n /= 2, i++)
			{
				int sum = 0;
				for (int j = 0; j < n; j++)
				{
					sum += grid[i][i+j] + grid[i+j][N - 1 - i]
						+ grid[N - 1 - i][N - 1 - j-i] + grid[N - 1 - j-i][i];
				}
				cout << ' ' << sum;
			}

			cout << ' ' << grid[N / 2][N / 2];
		}


		cout << '\n';
	}



	return 0;
}

