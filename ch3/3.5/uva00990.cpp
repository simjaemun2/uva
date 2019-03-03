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

const int MAX_N = 30;
const int MAX_T = 1000;

int tc, TC;
int N, T, W;
int sum;
int D[MAX_N], V[MAX_N];
int cache[MAX_N+1][MAX_T + 1];

int dp(int n, int t)
{
	int& ret = cache[n][t];

	if (t == 0 || n == N)
		return ret = 0;

	if (ret != -1)
		return ret;

	ret = dp(n+1, t);

	if (t >= 3 * W*D[n] && ret < dp(n + 1, t - 3 * W*D[n]) + V[n])
	{
		ret = dp(n + 1, t - 3 * W*D[n]) + V[n];
	}

	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	bool isFirst = true;
	while (cin >> T >> W >> N)
	{
		if (!isFirst)
			cout << '\n';
		isFirst = false;

		for (int n = 0; n < N; n++)
		{
			cin >> D[n] >> V[n];
		}

		memset(cache, -1, sizeof cache);

		int answer = dp(0, T);

		cout << answer << '\n';

		vector<int> r;

		for (int n = 0; n < N; n++)
		{
			if (answer == cache[n+1][T - 3*W*D[n]] + V[n])
			{
				r.push_back(n);
				T -= 3 * W*D[n];
				answer -= V[n];
			}
		}

		cout << r.size() << '\n';

		for (int n : r)
		{
			cout << D[n] << ' ' << V[n] << '\n';
		}
	}

	return 0;
}

