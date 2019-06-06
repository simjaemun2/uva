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
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;

const int INF = 987654321;
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1 };
int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 1000000;
int N, M;



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	//tc = 1;
	
	//while (cin >> N)

	cin >> TC;
	for(tc=1;tc<=TC;tc++)
	{
		
		if (tc != 1)
			cout << '\n';
			
		cin >> N;

		VVI adj(N);

		for (int n = 0; n < N; n++)
		{
			cin >> M >> M;
			for (int m = 0; m < M; m++)
			{
				int a;
				cin >> a;
				adj[n].push_back(a);
			}
		}
		
		int u, v;
		cin >> u >> v;

		queue<PII> q;
		VB visited(N);
		visited[u] = true;
		q.push({ 0, u });

		int answer;

		while (!q.empty())
		{
			int cur = q.front().second;
			int step = q.front().first;
			q.pop();

			if (cur == v)
			{
				answer = step;
				break;
			}

			for (int next : adj[cur])
			{
				if (!visited[next])
				{
					visited[next] = true;
					q.push({ step + 1, next });
				}
			}
		}

		cout << u << ' ' << v << ' ' << answer - 1 << '\n';
	}


	return 0;
}