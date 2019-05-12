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
const int MAX_N = 500;
const int MAX_D = 4;


int tc, TC;
int N, M;

int DY[] = { -1,0,1,0,-1,-1,1,1};
int DX[] = { 0,-1,0,1,-1,1,-1,1};


bool visited[MAX_N + 1];
vector<vector<PII> > v;
int maxP;

int dfs(int u)
{
	int ret = 1;
	visited[u] = true;
	for (auto p : v[u])
	{
		if (!visited[p.first] && p.second == maxP)
		{
			ret += dfs(p.first);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N >> M, N | M)
	{
		memset(visited, false, sizeof visited);

		v = vector<vector<PII> >(N + 1);
		maxP = -2147483648;
		
		for (int m = 0; m < M; m++)
		{
			int a, b, p;
			cin >> a >> b >> p;
			v[a].push_back({ b,p });
			v[b].push_back({ a,p });
			
			maxP = max(maxP, p);
		}

		int answer = 1;

		for (int n = 1; n <= N; n++)
		{
			if (!visited[n])
			{
				answer = max(answer, dfs(n));
			}
		}

		cout << answer << '\n';
	}
	

	return 0;
}



