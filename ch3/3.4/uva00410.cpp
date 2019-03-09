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
const int MAX_C = 5;
const int MAX_S = 10;
int tc;
int S, C;

bool compare(const II& a, const II& b)
{
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> C >> S)
	{
		cout << "Set #" << ++tc << '\n';

		vector<int > v(2 * C, 0);

		double sum = 0.0;
		double im = 0.0;

		for (int s = 0; s < S; s++)
		{
			cin >> v[s];
			sum += v[s];
		}

		sort(v.begin(), v.end());

		sum /= C;

		for (int i = 0; i < C; i++)
		{
			cout << ' ' << i << ':';
			if (v[i])
				cout << ' ' << v[i];
			if (v[2*C-i-1])
				cout << ' ' << v[2 * C - i - 1];
			cout << '\n';
			im += abs(sum - v[i] - v[2 * C - i - 1]);
		}

		printf("IMBALANCE = %.5lf\n\n", im);


	}


	return 0;
}