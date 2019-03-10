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
const int MAX_M = 5000;


int tc, TC;
int M;


bool compare(const II& a, const II& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin >> M;

		vector<II> v, result;

		int l, r;
		while (cin >> l >> r, !(l == 0 && r == 0))
		{
			v.push_back({ l,r });
		}

		sort(v.begin(), v.end(), compare);

		int right = 0;
		int answer = 0;

		for (int i = 0, j; i < v.size(); i++)
		{
			if (v[i].second <= 0)
				continue;

			if (v[i].first > right)
			{
				answer = 0;
				break;
			}

			for (j = i + 1; j < v.size() && v[j].first <= right; j++)
			{
				if (v[i].second < v[j].second)
				{
					i = j;
				}
			}

			right = v[i].second;
			answer++;
			result.push_back(v[i]);

			if (right >= M)
				break;
		}

		if (answer > 0 && result.back().second < M)
			answer = 0;


		cout << answer << '\n';
		
		if (answer)
		{
			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i].first << ' ' << result[i].second << '\n';
			}
		}

	}

	
	


	return 0;
}