#define _CRT_SECURE_NO_WARNINGS 

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

using namespace std;

typedef long long int LL;

const int MAX_N = 10000;

int tc, TC;
int N;
int input[MAX_N];

bool compare(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b)
{
	if (a.first == b.first)
		return a.second.first > b.second.first;
	return a.first > b.first;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N)
	{
		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		vector<int> inc(1, -1);
		vector<int> dec(1, -1);

		vector<int> lis_inc(N);
		vector<int> lis_dec(N);

		for (int n = 0; n < N; n++)
		{
			if (inc.back() < input[n])
			{
				inc.push_back(input[n]);
				lis_inc[n] = inc.size() - 1;
			}
			else
			{
				auto it = lower_bound(inc.begin(), inc.end(), input[n]);
				*it = input[n];
				lis_inc[n] = it - inc.begin();
			}

			if (dec.back() < input[N - n - 1])
			{
				dec.push_back(input[N - n - 1]);
				lis_dec[N - n - 1] = dec.size() - 1;
			}
			else
			{
				auto it = lower_bound(dec.begin(), dec.end(), input[N - n - 1]);
				*it = input[N - n - 1];
				lis_dec[N - n - 1] = it - dec.begin();
				
			}
		}

		int answer = 0;

		for (int n = 0; n < N; n++)
		{
			answer = max(answer, min(lis_inc[n], lis_dec[n]) * 2 - 1);
		}

		cout << answer << '\n';
	}

	return 0;
}

