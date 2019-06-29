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

const int MAX_N = 100;
const int MOD = 100000;

int L, T;

VVI adj;
VPII cache;

PII dp(int n)
{
	PII& ret = cache[n];

	if (ret.first != -1)
		return ret;

	ret.first = ret.second = 0;

	for (int v : adj[n])
	{
		PII next = dp(v);

		ret.first = (ret.first + next.first + next.second * (n == 1 ? 0 : 1)) % MOD;
		ret.second = (ret.second + next.second) % MOD;
	}

	return ret;
}


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> L >> T;

		adj = VVI(L + 1);
		cache = VPII(L + 1, { -1,-1 });

		for (int t = 0; t < T; t++)
		{
			int y, x;
			cin >> x >> y;
			adj[x].push_back(y);
		}

		cache[L].first = cache[L].second = 1;

		PII answer = dp(1);

		cout << "Case " << tc << ": " << answer.first << ' ' << answer.second << '\n';
	}
	
	return 0;
}