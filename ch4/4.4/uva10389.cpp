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

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};

const int MAX_N = 250;
double adj[MAX_N][MAX_N];
int N;

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
			
		memset(adj, 0, sizeof adj);

		getline(cin, line);
		stringstream iss(line);
		vector<PDD> v(MAX_N);
		
		iss >> v[0].second >> v[0].first >> v[1].second >> v[1].first;
		
		N = 2;

		while (getline(cin, line) && line.size())
		{
			iss = stringstream(line);
			iss >> v[N].second >> v[N].first;
			N++;
			
			while (iss >> v[N].second >> v[N].first, v[N].first > -0.5)
			{
				adj[N][N - 1] = hypot(v[N].first - v[N - 1].first, v[N].second - v[N - 1].second);
				adj[N - 1][N] = adj[N][N - 1];
				N++;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (adj[i][j] == 0.0)
				{
					adj[i][j] = hypot(v[i].first - v[j].first, v[i].second - v[j].second) * 4.0;
				}
			}
		}

		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

		cout << (int)(adj[0][1] * 6 / 4000 + 0.5) << '\n';
	}

	

	return 0;
}