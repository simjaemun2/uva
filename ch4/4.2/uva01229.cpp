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


const int INF = 987654321;
int tc, TC;
int DY[] = { -1,0,1,0,-1,-1,1,1 };
int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 200;
int N, M;

const int VISITED = 1;
const int UNVISITED = 0;


VVI adj;
VI dfs_num, dfs_low;
vector<bool> visited;
int dfs_count;
VI st;
VI answer, answer2;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = ++dfs_count;
	visited[u] = true;
	st.push_back(u);

	for (int v : adj[u])
	{
		if (dfs_num[v] == UNVISITED)
		{
			dfs(v);
		}

		if (visited[v] == true)
		{
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

	if (dfs_low[u] == dfs_num[u])
	{
		VI a;
		while (true)
		{
			int v = st.back();
			st.pop_back();
			visited[v] = false;
			a.push_back(v);
			
			if (v == u)
			{
				break;
			}
		}

		if (a.size() > 1)
		{
			answer.push_back(a[0]);
		}
	}
}

void dfs2(int u)
{
	if (!visited[u])
	{
		visited[u] = true;
		answer2.push_back(u);
		for (int v : adj[u])
		{
			dfs2(v);
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	tc = 1;
	string line;

	while (true)
	{
		getline(cin, line);
		N = stoi(line);

		if (!N)
			break;

		adj = VVI(N + 1);
		
		dfs_low = VI(N + 1, UNVISITED);
		dfs_num = VI(N + 1, UNVISITED);
		visited = vector<bool>(N + 1, false);
		
		st.clear();
		dfs_count = 0;
		
		answer.clear();
		answer2.clear();
		map<string, int> wordMap;
		vector<string> words;

		for (int n = 0; n < N; n++)
		{
			getline(cin, line);
			istringstream iss(line);
			string u, v;
			int iu, iv;
			iss >> u;

			auto it = wordMap.find(u);

			if (it == wordMap.end())
			{
				words.push_back(u);
				iu = words.size();
				wordMap[u] = iu;
			}
			else
			{
				iu = it->second;
			}

			while (iss >> v)
			{
				auto it = wordMap.find(v);

				if (it == wordMap.end())
				{
					words.push_back(v);
					iv = words.size();
					wordMap[v] = iv;
				}
				else
				{
					iv = it->second;
				}

				if (find(adj[iu].begin(), adj[iu].end(), iv) == adj[iu].end())
				{
					adj[iu].push_back(iv);
				}
			}

		}
		

		for (int n = 1; n <= N; n++)
		{
			if (dfs_num[n] == UNVISITED)
			{
				dfs(n);
			}
		}

		for (int u : answer)
		{
			dfs2(u);
		}

		vector<string> as;
		
		for (int i : answer2)
		{
			as.push_back(words[i - 1]);
		}

		sort(as.begin(), as.end());

		cout << as.size() << '\n' << as[0];
		
		for(int i=1; i < as.size(); i++)
		{
			cout << ' ' << as[i];
		}

		cout << '\n';
	}

	return 0;
}



