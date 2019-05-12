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
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1};
int DX[] = { 0,-1,0,1,-1,1,-1,1};

const int MAX_N = 20;

char dfs_c[MAX_N + 1];
char c_i[128];

int N;
bool comp[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs(string s)
{
	if (s.size() == N)
	{
		cout << s << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[j] && comp[i][j])
				{
					return;
				}
			}

			visited[i] = true;
			dfs(s + dfs_c[i]);
			visited[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	string line;
	bool isFirst = true;
	while (getline(cin, line))
	{
		if (!isFirst)
			cout << '\n';
		isFirst = false;

		memset(comp, false, sizeof comp);
		memset(visited, false, sizeof visited);
		N = 0;
		istringstream iss(line);
		string t1,t2;
		while (iss >> t1)
		{
			dfs_c[N++] = t1[0];
		}

		sort(dfs_c, dfs_c + N);

		for (int n = 0; n < N; n++)
		{
			c_i[dfs_c[n]] = n;
		}

		getline(cin, line);
		iss = istringstream(line);

		while (iss >> t1 >> t2)
		{	
			comp[c_i[t1[0]]][c_i[t2[0]]] = true;
		}

		dfs("");
	}
	
	

	return 0;
}



