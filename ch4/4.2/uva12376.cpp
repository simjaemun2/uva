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
#include <limits.h>
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;


const int INF = 987654321;
const int SZ_N = 100;

int tc, TC;
int N, M;

int scores[SZ_N];
vector<vector<int> > adj;
int maxScore, maxIndex;
void dfs(int n, int sum)
{
	int nextIndex = 0;
	int maxNext = 0;

	for (int next : adj[n])
	{
		if (maxNext < scores[next])
		{
			maxNext = scores[next];
			nextIndex = next;
		}
	}

	if (nextIndex)
	{
		dfs(nextIndex, sum + maxNext);
	}
	else
	{
		maxScore = sum;
		maxIndex = n;
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> M;

		adj = vector<vector<int> >(N);

		for (int n = 0; n < N; n++)
		{
			cin >> scores[n];
		}

		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		

		dfs(0, 0);

		cout << "Case " << tc << ": " << maxScore << ' ' << maxIndex << '\n';
	}

	
	return 0;
}

