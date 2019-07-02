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

const int MAX_GAS = 200;
const int MAX_DIST = 10000;

int D;

int stations[MAX_DIST + 1];
LL cache[MAX_DIST + 1][MAX_GAS + 1];

LL dp(int dist, int gas)
{
	if(dist == D && gas >= MAX_GAS / 2)
	{
		return 0LL;
	}

	LL& ret = cache[dist][gas];
	if (ret != -1)
		return ret;

	ret = INF * 10000LL;

	if (dist + 1 <= D && gas > 0)
	{
		ret = min(ret, dp(dist + 1, gas - 1));
	}

	if (stations[dist] > 0 && gas + 1 <= MAX_GAS)
	{
		ret = min(ret, dp(dist, gas + 1) + stations[dist]);
	}

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
			cout << '\n';

		getline(cin, line);
		D = stoi(line);

		memset(cache, -1, sizeof cache);
		memset(stations, -1, sizeof stations);
		
		int a, b;
		while (getline(cin, line) && line.size())
		{
			istringstream iss(line);
			iss >> a >> b;
			
			if (a > D)
			{
				continue;
			}
			else
			{
				stations[a] = b;
			}
		}

		LL answer = dp(0, MAX_GAS/2);

		if (answer == INF * 10000LL)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << answer << '\n';
		}
	}
	
	return 0;
}