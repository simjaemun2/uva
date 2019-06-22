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
//            S N W E
//            0 1 2 3
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};
const int SOUTH = 0;
const int NORTH = 1;
const int WEST = 2;
const int EAST = 3;

int N, T, M;

struct Vertex {
	int start;
	int end;
	int station;
	int orgStart;
};

bool operator<(Vertex a, Vertex b)
{
	return a.end < b.end;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	int tc = 1;
	while (cin >> N, N)
	{
		map<string, int> m;
		vector<vector<Vertex > > adj(N);
		map<PII, int> dist;

		for (int n = 0; n < N; n++)
		{
			string s;
			cin >> s;
			m[s] = n;
		}

		cin >> T;
		while (T--)
		{
			cin >> M;

			string pStation, pStart;
			cin >> pStart >> pStation;

			int pStationIndex = m[pStation];
			int ps = stoi(pStart);

			dist[{pStationIndex, ps}] = -1;

			while (--M)
			{
				string start, station;

				cin >> start >> station;

				int st = stoi(start);

				dist[{m[station], st}] = -1;

				Vertex vertex;
				vertex.start = ps;
				vertex.end = st;
				vertex.station = m[station];
				adj[pStationIndex].push_back(vertex);

				ps = st;
				pStationIndex = m[station];
			}
		}

		string st, s, e;
		cin >> st >> s >> e;
		int t = stoi(st);
		int si = m[s];
		int ei = m[e];

		priority_queue<Vertex> pq;
		
		Vertex sv;
		sv.end = t;
		sv.orgStart = 0;
		sv.station = si;

		pq.push(sv);

		int aStart = INF;
		int aEnd = INF;

		while (!pq.empty())
		{
			int cStation = pq.top().station;
			int cEnd = pq.top().end;
			int cOrgStart = pq.top().orgStart;

			pq.pop();

			if (cStation == ei)
			{
				if (aEnd > cEnd || aEnd == cEnd && aStart < cOrgStart)
				{
					aEnd = cEnd;
					aStart = cOrgStart;
				}

				continue;
			}

			for (Vertex candi : adj[cStation])
			{
				if (cEnd <= candi.start && (!cOrgStart || dist[{candi.station, candi.start}] < cOrgStart))
				{
					Vertex nv;
					nv.end = candi.end;

					if (cOrgStart)
					{
						nv.orgStart = cOrgStart;
					}
					else
					{
						nv.orgStart = candi.start;
					}
					
					nv.station = candi.station;
					pq.push(nv);
					dist[{candi.station, candi.start}] = nv.orgStart;
				}
			}
		}

		if (aStart == INF)
		{
			cout << "No connection\n";
		}
		else
		{
			printf("%02d%02d %02d%02d\n", aStart / 100, aStart % 100, aEnd / 100, aEnd % 100);
		}

		tc++;
	}

	return 0;
}