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
const int MAX_N = 10000;
const int MAX_D = 4;


int tc, TC;
int N,M,L;
int grid[MAX_N][MAX_N];

int DY[] = { -1,1,0,0,-1,-1,1,1};
int DX[] = { 0,0,-1,1,-1,1,-1,1};

int cnt;

bool visited[MAX_N + 1];
vector<vector<int> > v;
void dfs(int a)
{
	visited[a] = true;
	cnt++;
	for (int n : v[a])
	{
		if (!visited[n])
		{
			dfs(n);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> M >> L;

		v = vector<vector<int> >(N + 1);
		memset(visited, false, sizeof visited);
		
		for (int m = 0; m < M; m++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		cnt = 0;

		for (int l = 0; l < L; l++)
		{
			int a;
			cin >> a;
			if(!visited[a])
				dfs(a);
		}

		cout << cnt << '\n';
	}



	return 0;
}

