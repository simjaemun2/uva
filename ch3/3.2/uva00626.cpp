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
const int MAX_N = 100;

int tc, TC;
int N;

int input[MAX_N+1][MAX_N+1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N)
	{
		vector<vector<int> > v(N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> input[i][j];
				if(input[i][j])
					v[i].push_back(j);
			}
		}

		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				for (int k = 0; k < v[v[i][j]].size(); k++)
				{
					if (v[v[i][j]][k] != i && input[v[v[i][j]][k]][i])
					{
						if (i < v[i][j] && v[i][j] < v[v[i][j]][k]
							|| i > v[i][j] && v[i][j] > v[v[i][j]][k])
						{
							cout << i + 1 << ' ' << v[i][j] + 1 << ' ' << v[v[i][j]][k] + 1 << '\n';
							cnt++;
						}
					}
				}
			}
		}

		cout << "total:" << cnt << "\n\n";
	}
	
	
	return 0;
}