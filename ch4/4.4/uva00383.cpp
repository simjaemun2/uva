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

const int MAX_N = 100;
int N, M, P;

const int COST = 100;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cout << "SHIPPING ROUTES OUTPUT\n";

	cin >> TC;
	for(tc=1;tc<=TC;tc++)
	
	//while(cin >> N >> M, N|M)
	//while (cin >> N)
	{
		/*
		if (tc != 1)
			cout << '\n';
		*/
		
		cin >> N >> M >> P;
		
		map<string, int > indexMap;
		VVI adj(N, VI(N, INF));

		for (int n = 0; n < N; n++)
		{
			string s;
			cin >> s;
			indexMap[s] = indexMap.size();
		}

		for (int m = 0; m < M; m++)
		{
			string a,b;
			cin >> a >> b;
			adj[indexMap[a]][indexMap[b]] = 1;
			adj[indexMap[b]][indexMap[a]] = 1;
		}

		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (adj[i][k] != INF && adj[k][j] != INF)
					{
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					}
				}
			}
		}

		cout << "\nDATA SET  " << tc << "\n\n";

		for(int p=0; p<P; p++)
		{
			string a, b;
			int t;
			cin >> t >> a >> b;

			int d = adj[indexMap[a]][indexMap[b]];
			if (d == INF)
			{
				cout << "NO SHIPMENT POSSIBLE\n";
			}
			else
			{
				cout << '$' << COST * t * d << '\n';
			}
		}		
	}

	cout << "\nEND OF OUTPUT\n";

	return 0;
}