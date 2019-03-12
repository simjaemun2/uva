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
const int MAX_N = 20000;

int TC;
int N;

bool compare(const PII& a, const PII& b)
{
	return a.second > b.second;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		cout << "Case " << ++TC << ": ";

		vector<PII> v(N);

		for (int n = 0; n < N; n++)
		{
			cin >> v[n].first >> v[n].second;
		}


		sort(v.begin(), v.end(), compare);

		int answer = 0;
		int acc = 0;

		for (int n = 0; n < N; n++)
		{
			acc += v[n].first;
			answer = max(answer, acc + v[n].second);
		}

		cout << answer << '\n';
	}
	
	return 0;
}