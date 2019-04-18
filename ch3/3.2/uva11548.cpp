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


const int INF = 1000000;
const int MAX_N = 70;

int tc, TC;
int N;

string input[MAX_N];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> input[0];
		int answer = 0;

		for (int i = 1; i < N; i++)
		{
			cin >> input[i];

			for (int j = 0; j < i; j++)
			{
				if (input[i].size() > answer && input[j].size() > answer)
				{
					for (int ii = 0; ii < input[i].size(); ii++)
					{
						int ans = 0;

						for (int jj = ii, k = 0; jj < input[i].size() && k < input[j].size(); jj++, k++)
						{
							if (input[i][jj] == input[j][k])
							{
								ans++;
							}
						}

						answer = max(answer, ans);
					}

					for (int ii = 0; ii < input[j].size(); ii++)
					{
						int ans = 0;

						for (int jj = ii, k = 0; jj < input[j].size() && k < input[i].size(); jj++, k++)
						{
							if (input[j][jj] == input[i][k])
							{
								ans++;
							}
						}

						answer = max(answer, ans);
					}
				}
			}
		}

		cout << answer << '\n';


	}
	
	return 0;
}


