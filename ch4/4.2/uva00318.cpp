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
const int MAX_N = 100;

int tc, TC;
int N,M;

double adj[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];
double dist[MAX_N + 1];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N >> M, N | M)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				adj[i][j] = INF;
			}

			adj[i][i] = 0;
			dist[i] = INF;
			visited[i] = false;
		}

		for (int m = 0; m < M; m++)
		{
			int a, b;
			double l;
			cin >> a >> b >> l;
			adj[a][b] = l;
			adj[b][a] = l;
		}

		int src = 1;
		visited[src] = true;
		dist[src] = 0;

		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= N; j++)
			{
				if (adj[src][j] && dist[j] > dist[src] + adj[src][j])
				{
					dist[j] = dist[src] + adj[src][j];
				}
			}

			int mind = INF;

			for (int j = N; j >= 1; j--)
			{
				if (!visited[j] && mind > dist[j])
				{
					src = j;
					mind = dist[j];
				}
			}
			visited[src] = true;
		}

		double answer = dist[src];

		int des = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (adj[i][j] < INF && answer < 0.5 * (dist[i] + dist[j] + adj[i][j]))
				{
					answer = 0.5 * (dist[i] + dist[j] + adj[i][j]);
					src = i;
					des = j;
				}
			}
		}

		printf("System #%d\nThe last domino falls after %.1f seconds,", ++tc, answer);
		
		if (des)
		{
			printf(" between key dominoes %d and %d.\n\n",src,des);
		}
		else
		{
			printf(" at key domino %d.\n\n", src);
		}
	}
	
	
	return 0;
}


