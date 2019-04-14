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
const int MAX_N = 3000;


int tc, TC;
int V,E;

bool input[MAX_N + 1][MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	scanf("%d", &TC);

	for (tc = 1; tc <= TC; tc++)
	{
		scanf("%d %d", &V, &E);

		memset(input, false, sizeof input);

		for (int e = 0; e < E; e++)
		{
			int i, j;
			cin >> i >> j;
			input[i][j] = true;
			input[j][i] = true;
			
		}

		int answer = 0;

		for (int i = 1; i < V - 1; i++)
		{
			for (int j = i + 1; j < V; j++)
			{
				if (input[i][j])
				{
					for (int k = j + 1; k <= V; k++)
					{
						if (input[j][k] && input[k][i])
						{
							answer++;
						}
					}
				}
			}
		}

		cout << answer << '\n';
	}
	

	return 0;
}
