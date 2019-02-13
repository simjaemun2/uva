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

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		vector<pair<int, int> > v(N);

		for (int n = 0; n < N; n++)
		{
			cin >> v[n].first >> v[n].second;
		}

		sort(v.begin(), v.end(), compare);

		vector<int> lis(1, -1);

		for (auto p : v)
		{
			if (lis.back() <= p.second)
			{
				lis.push_back(p.second);
			}
			else
			{
				*upper_bound(lis.begin(), lis.end(), p.second) = p.second;
			}
		}

		cout << lis.size() - 1 << '\n';
	}


	return 0;
}

