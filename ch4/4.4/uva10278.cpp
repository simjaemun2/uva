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
typedef vector<double > VD;
typedef vector<PII> VPII;
typedef vector<vector<PII> > VVPII;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};

int F,I, S;
VVPII adj;

void dijkstra(VI& dist, int src)
{
	dist[src] = 0;
	priority_queue<PII> pq;
	pq.push({ 0, src });

	while (!pq.empty())
	{
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();

		if (dist[u] >= d)
		{
			dist[u] = d;

			for (auto p : adj[u])
			{
				int v = p.second;
				int vd = p.first;

				if (dist[v] > d + vd)
				{
					dist[v] = d + vd;
					pq.push({ -dist[v], v });
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	string line;
	getline(cin, line);
	TC = stoi(line);
	getline(cin, line);

	for (tc = 1; tc <= TC; tc++)
	{
		if (tc != 1)
			cout << '\n';

		getline(cin, line);
		istringstream iss(line);
		iss >> F >> I;

		VI v, dist(I + 1, INF);
		adj = VVPII(I + 1);
		
		int f;

		if (iss >> f)
		{
			v.push_back(f);
		}
		else
		{
			getline(cin, line);
			iss = istringstream(line);
		}

		while (iss >> f)
		{
			v.push_back(f);
		}

		
		

		while (getline(cin, line) && line.size())
		{
			iss = istringstream(line);
			int a, b, d;
			iss >> a >> b >> d;

			adj[a].push_back({ d,b });
			adj[b].push_back({ d,a });
		}
		
		for (int f : v)
		{
			dijkstra(dist, f);
		}

		int answer = INF;
		int answerIndex = 0;

		for (int src = 1; src <= I; src++)
		{
			VI tdist = dist;

			dijkstra(tdist, src);

			int maxDist = 0;
			
			for (int i = 1; i <= I; i++)
			{
				maxDist = max(maxDist, tdist[i]);
			}

			if (answer > maxDist)
			{
				answer = maxDist;
				answerIndex = src;
			}
		}

		cout << answerIndex << '\n';
	}

	

	return 0;
}