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
//            N   W  S  E
//            0   1  2  3
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1};
int DX[] = {  0, -1, 0, 1 , -1,1,-1,1};

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int K,N;

const int MAX_N = 26;
vector<char> v;
map<char, int> m;
map<char, string> adj;
int dist[MAX_N];
int cache[MAX_N];

int dp(char c)
{
	int& ret = cache[m[c]];

	if (ret != -1)
		return ret;

	ret = 0;

	for (char next : adj[c])
	{
		ret = max(ret, dp(next));
	}

	ret += dist[m[c]];

	return ret;
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
		{
			cout << '\n';
		}

		v.clear();
		m.clear();
		adj.clear();

		memset(cache, -1, sizeof cache);

		while (getline(cin, line) && line.size())
		{
			istringstream iss(line);
			string dst;
			char src;
			int d;

			iss >> src >> d;

			v.push_back(src);
			m[src] = m.size();
			dist[m.size() - 1] = d;

			if (iss >> dst)
			{
				adj[src] = dst;
			}
			else
			{
				adj[src] = "";
			}
		}

		int answer = 0;

		for (char c : v)
		{
			answer = max(answer, dp(c));
		}

		cout << answer << '\n';
	}
	
	
	return 0;
}