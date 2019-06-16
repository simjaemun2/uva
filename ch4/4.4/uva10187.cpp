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
typedef pair<int, PII> PPII;
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

int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;

		string a, b;
		int de,ti, ai, bi, ar;

		map<string, int> m;
		vector< vector< pair< int, PII > > > adj;

		for (int n = 0; n < N; n++)
		{
			cin >> a >> b >> de >> ti;

			if (de <= 6)
			{
				de += 24;
			}

			de -= 18;

			ar = de + ti;
				
			if (de < 0 || de >= 12 || ti >= 12 || ar > 12)
			{
				continue;
			}


			if (m.find(a) == m.end())
			{
				ai = m.size();
				m[a] = ai;
				adj.push_back(vector< pair<int, PII> >());
			}
			else
			{
				ai = m[a];
			}

			if (m.find(b) == m.end())
			{
				bi = m.size();
				m[b] = bi;
				adj.push_back(vector< pair<int, PII> >());
			}
			else
			{
				bi = m[b];
			}

			adj[ai].push_back({ bi, {de, ar} });
		}

		cin >> a >> b;

		cout << "Test Case " << tc << ".\n";

		if (a == b)
		{
			cout << "Vladimir needs 0 litre(s) of blood.\n";
		}
		else if(m.find(a) == m.end() || m.find(b) == m.end())
		{
			cout << "There is no route Vladimir can take.\n";
		}
		else
		{
			ai = m[a];
			bi = m[b];

			VVI dist(m.size(), VI(13, INF));
			priority_queue<pair<int, PII > > pq;
			dist[ai][0] = 0;
			pq.push({ 0, {ai, 0} });

			while (!pq.empty())
			{
				int d = -pq.top().first;
				int u = pq.top().second.first;
				int car = pq.top().second.second;

				pq.pop();

				if (dist[u][car] >= d)
				{
					for (auto p : adj[u])
					{
						int v = p.first;
						int nde = p.second.first;
						int nar = p.second.second;

						int nd = nde < car ? d + 1 : d;

						if (dist[v][nar] > nd)
						{
							dist[v][nar] = nd;
							pq.push({ -nd, {v, nar} });
						}
					}
				}
			}

			int answer = INF;
			for (int a : dist[bi])
			{
				answer = min(answer, a);
			}

			if (answer == INF)
			{
				cout << "There is no route Vladimir can take.\n";
			}
			else
			{
				cout << "Vladimir needs " << answer << " litre(s) of blood.\n";
			}
		}
	}
	
	

	return 0;
}