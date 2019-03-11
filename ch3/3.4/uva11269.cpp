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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_N = 20;
const int MAX_SG = 100;

int tc, TC;
int N;

bool compare(const PII& a, const PII& b)
{
	return a.first + max(a.second, b.first) + b.second
		< b.first + max(b.second, a.first) + a.second;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		vector<PII> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i].first;
		}

		for (int i = 0; i < N; i++)
		{
			cin >> v[i].second;
		}

		sort(v.begin(), v.end(), compare);

		int t1 = 0;
		int t2 = v[0].first;

		for (int i = 0; i < N; i++)
		{
			t1 += v[i].first;
			t2 = max(t1, t2);
			t2 += v[i].second;
		}

		cout << t2 << '\n';
	}
	
	


	return 0;
}