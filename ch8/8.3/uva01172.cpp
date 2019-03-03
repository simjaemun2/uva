#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>
#include <math.h>
#include <functional>

using namespace std;

#define INF 987654321

#define MAX_N 1000

int N,S;

string nos[MAX_N + 1];
string sos[MAX_N + 1];
int ntv[MAX_N + 1];
int stv[MAX_N + 1];

int ctv[MAX_N + 1][MAX_N + 1];
int cnt[MAX_N + 1][MAX_N + 1];

int main(int argc, char** argv)
{
	int TC;
	cin >> TC;

	while (TC--)
	{
		cin >> N;
		for (int n = 1; n <= N; n++)
			cin >> nos[n] >> nos[n] >> ntv[n];

		cin >> S;
		for (int s = 1; s <= S; s++)
			cin >> sos[s] >> sos[s] >> stv[s];

		for (int n = 1; n <= N; n++)
		{
			for (int s = 1; s <= S; s++)
			{
				ctv[n][s] = ctv[n - 1][s];
				cnt[n][s] = cnt[n - 1][s];

				if (ctv[n][s] < ctv[n][s - 1])
				{
					ctv[n][s] = ctv[n][s - 1];
					cnt[n][s] = cnt[n][s - 1];
				}
				else if (ctv[n][s] == ctv[n][s - 1] && cnt[n][s] > cnt[n][s-1])
				{
					cnt[n][s] = cnt[n][s - 1];
				}

				if (nos[n] == sos[s])
				{
					if (ctv[n][s] < ctv[n - 1][s - 1] + ntv[n] + stv[s])
					{
						ctv[n][s] = ctv[n-1][s - 1] + ntv[n] + stv[s];
						cnt[n][s] = cnt[n-1][s - 1] + 1;
					}
					else if (ctv[n][s] == ctv[n - 1][s - 1] + ntv[n] + stv[s] && cnt[n][s] > cnt[n - 1][s - 1] + 1)
					{
						cnt[n][s] = cnt[n - 1][s - 1] + 1;
					}
				}
			}
		}

		cout << ctv[N][S] << ' ' << cnt[N][S] << '\n';
	}

	
	return 0;
}