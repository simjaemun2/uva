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

const int INF = 2000000000;
const int MAX_N = 10000;


int N;
double L, W;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> L >> W)
	{
		W /= 2.0;

		vector<pair<double, double> > v;

		for (int n = 0; n < N; n++)
		{
			double c, r;
			cin >> c >> r;

			if (r > W)
			{
				double dx = sqrt(r*r - W * W);
				v.push_back({ c - dx, c + dx });
			}
		}

		sort(v.begin(), v.end());

		double right = 0.0;
		int answer = 0;

		for (int i = 0, j; i < v.size(); i = j)
		{
			if (v[i].first > right)
				break;

			for (j = i + 1; j < v.size() && v[j].first <= right; j++)
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

		cout << answer << '\n';
	}


	return 0;
}