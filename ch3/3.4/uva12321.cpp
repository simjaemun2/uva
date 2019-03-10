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
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_M = 5000;

int tc, TC;
int L, G;



int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> L >> G, L+G)
	{
		vector<PII> v;

		for (int g = 0; g < G; g++)
		{
			int x, r;
			cin >> x >> r;
			v.push_back({ x - r, x + r });
		}

		sort(v.begin(), v.end());

		int answer = 0;
		int right = 0;

		for (int i = 0, j; i < v.size(); i++)
		{
			if (v[i].first > right)
			{
				answer = -1;
				break;
			}

			for (int j = i + 1; j < v.size() && v[j].first <= right; j++)
			{
				if (v[j].second > v[i].second)
				{
					i = j;
				}
			}

			answer++;
			right = v[i].second;

			if (right >= L)
				break;
		}

		if (right < L)
			answer = -1;

		if (answer == -1)
			cout << "-1\n";
		else
			cout << G - answer << '\n';
	}
	
	


	return 0;
}