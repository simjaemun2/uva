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
	
	tc = 1;

	while (cin >> N, N)
	{
		map<int, int> m;
		int u, v;
		VVI adj(2*N);

		for (int n = 0; n < N; n++)
		{
			int iu, iv;
			cin >> u >> v;
			
			if (m.find(u) == m.end())
			{
				iu = m.size();
				m[u] = iu;
			}
			else
			{
				iu = m[u];
			}

			if (m.find(v) == m.end())
			{
				iv = m.size();
				m[v] = iv;
			}
			else
			{
				iv = m[v];
			}

			adj[iu].push_back(iv);
			adj[iv].push_back(iu);
		}

		while (cin >> u >> v, u | v)
		{
			VB visited(2*N, false);
			int sum = m.size();

			if (m.find(u) != m.end())
			{
				queue<PII> q;

				q.push({ 0, m[u] });
				visited[m[u]] = true;

				while (!q.empty())
				{
					int step = q.front().first;
					int cur = q.front().second;

					q.pop();
					sum--;

					for (int next : adj[cur])
					{
						if (!visited[next] && step < v)
						{
							visited[next] = true;
							q.push({ step + 1, next });
						}
					}
				}
			}

			cout << "Case " << tc++ << ": " << sum
				<< " nodes not reachable from node " << u << " with TTL = " << v << ".\n";
		}
	}


	return 0;
}