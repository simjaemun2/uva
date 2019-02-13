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

const int MAX_N = 1000;

int tc, TC;
int N;

int LIS[MAX_N + 1];
int LIS_SIZE;
int P[MAX_N + 1];
int I[MAX_N + 1];


int my_lower_bound(int right, int key)
{
	int left = 0;

	while (left < right)
	{
		int mid = (left + right) / 2;

		if (LIS[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return right;
}


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
	
	int w, i;
	vector<pair<int, pair<int, int> > > v;

	while (cin >> w >> i)
	{
		v.push_back({ i, {w, v.size() + 1 } });
	}

	sort(v.begin(), v.end(), compare);

	int lis_end = 0;

	for (int n = 0; n < v.size(); n++)
	{
		int w = v[n].second.first;

		int p = my_lower_bound(LIS_SIZE, w);

		LIS[p] = w;
		I[p] = n;

		P[n] = p ? I[p - 1] : -1;

		if (p + 1 > LIS_SIZE)
		{
			LIS_SIZE = p + 1;
			lis_end = n;
		}
	}

	cout << LIS_SIZE << '\n';

	stack<int> s;

	for (; P[lis_end] != -1; lis_end = P[lis_end])
	{
		s.push(lis_end);
	}

	cout << v[lis_end].second.second << '\n';

	for (; !s.empty(); s.pop())
	{
		cout << v[s.top()].second.second << '\n';
	}

	return 0;
}

