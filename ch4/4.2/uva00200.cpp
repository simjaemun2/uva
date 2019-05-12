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

const int MAX_N = 26;

char dfs_c[MAX_N + 1];
char c_i[128];

int N;
bool comp[MAX_N][MAX_N];
bool visited[MAX_N];
bool used[MAX_N];

vector<int> v;

void dfs(int n)
{
	visited[n] = true;
	for (int i = 0; i < MAX_N; i++)
	{
		if (comp[n][i] && !visited[i])
		{
			dfs(i);
		}
	}
	v.push_back(n);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	memset(visited, false, sizeof visited);
	memset(comp, false, sizeof comp);
	memset(used, false, sizeof used);
	v.clear();

	string s1, s2;
	cin >> s1;
	while (cin >> s2, s2[0] != '#')
	{
		for (int i = 0; i < s1.size() && i < s2.size(); i++)
		{
			if (s1[i] != s2[i])
			{
				used[s1[i] - 'A'] = used[s2[i] - 'A'] = true;
				comp[s1[i] - 'A'][s2[i] - 'A'] = true;
				break;
			}
		}

		s1 = s2;
	}

	for (int i = 0; i < MAX_N; i++)
	{
		if (used[i] && !visited[i])
		{
			dfs(i);
		}
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << (char)(v[i] + 'A');
	}
	cout << '\n';

	return 0;
}



