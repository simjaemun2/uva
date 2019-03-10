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
int N;

struct Node {
	double ts;
	int idx;
};

bool compare(const Node& a, const Node& b)
{
	if (a.ts == b.ts)
	{
		return a.idx < b.idx;
	}

	return a.ts > b.ts;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	for(tc=1; tc<=TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin >> N;

		vector<Node> v(N);

		for (int n = 0; n < N; n++)
		{
			double t, s;
			cin >> t >> s;
			v[n].ts = s / t;
			v[n].idx = n + 1;
		}

		sort(v.begin(), v.end(), compare);

		cout << v[0].idx;

		for (int i=1; i<v.size(); i++)
		{
			cout << ' ' << v[i].idx;
		}

		cout << '\n';
	}
	
	


	return 0;
}