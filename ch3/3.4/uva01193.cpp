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
typedef pair<double, double > DD;

const int INF = 2000000000;
const int MAX_N = 10000;


int N;
double D;
int tc;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> D, N)
	{
		vector<DD > V;
		bool isPossible = true;

		for (int n = 0; n < N; n++)
		{
			double x, y;
			cin >> x >> y;
			
			if (y > D)
			{
				isPossible = false;
			}
			
			double dx = sqrt(D*D - y * y);
			
			V.push_back({ x - dx, x + dx });
		}

		int answer = -1;

		if (isPossible)
		{
			sort(V.begin(), V.end());

			answer = 0;

			for (int i = 0,j; i < N; i++)
			{
				answer++;
				for (j = i + 1; j < N; j++)
				{
					if (V[i].second >= V[j].first)
					{
						if (V[i].second >= V[j].second)
						{
							i = j;
						}	
					}
					else
					{
						i = j - 1;
						break;
					}
				}

				if (j == N)
					break;
			}
		}

		cout << "Case " << ++tc << ": " << answer << '\n';
	}


	return 0;
}