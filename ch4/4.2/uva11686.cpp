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
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1};
int DX[] = { 0,-1,0,1,-1,1,-1,1};

int N,M,A,B;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> M, N | M)
	{
		vector<vector<int> > adj(N + 1);
		vector<int> indegree(N + 1);
		vector<int> answer;

		for (int m = 0; m < M; m++)
		{
			cin >> A >> B;
			adj[A].push_back(B);
			indegree[B]++;
		}

		queue<int> q;

		for (int n = 1; n <= N; n++)
		{
			if (!indegree[n])
			{
				q.push(n);
			}
		}

		while (!q.empty())
		{
			int u = q.front();
			answer.push_back(u);
			q.pop();
			for (int v : adj[u])
			{
				if (!--indegree[v])
				{
					q.push(v);
				}
			}
		}

		if (answer.size() != N)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			for (int a : answer)
			{
				cout << a << '\n';
			}
		}
	}

	return 0;
}



