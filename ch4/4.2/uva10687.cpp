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
const int MAX_N = 1000;

int tc, TC;
int N;

PII stations[MAX_N];

bool visited[MAX_N];
int dist[MAX_N][MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N, N)
	{
		memset(visited, false, sizeof visited);

		for (int i = 0; i < N; i++)
		{
			cin >> stations[i].first >> stations[i].second;
			
			for (int j = 0; j < i; j++)
			{
				int dx = stations[i].first - stations[j].first;
				int dy = stations[i].second - stations[j].second;
				
				dist[i][j] = dist[j][i] = dx * dx + dy * dy;
			}
		}

		queue<int> q;
		q.push(0);

		int cnt = 1;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			visited[cur] = true;

			priority_queue<PII> pq;

			for (int i = 0; i < N; i++)
			{
				if (i != cur)
				{
					pq.push({ -dist[cur][i], i });
				}
			}

			if (!visited[pq.top().second])
			{
				q.push(pq.top().second);
			}
			pq.pop();

			if (!visited[pq.top().second])
			{
				q.push(pq.top().second);
			}
			pq.pop();
		}

		for (int i = 1; i < N; i++)
		{
			if (!visited[i])
				break;
			cnt++;
		}

		if (cnt == N)
		{
			cout << "All stations are reachable.\n";
		}
		else
		{
			cout << "There are stations that are unreachable.\n";
		}
	}

	
	return 0;
}

