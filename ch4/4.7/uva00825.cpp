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
int DY[] = { -1,  0, 1, 0 , -1,-1,1,1 };
int DX[] = { 0, -1, 0, 1 , -1,1,-1,1 };

const int NORTH = 0;
const int WEST = 1;
const int SOUTH = 2;
const int EAST = 3;

int N, M;

const int MAX_N = 1000;

int cache[MAX_N][MAX_N];
int input[MAX_N][MAX_N];




int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	string line;
	getline(cin, line);
	
	TC = stoi(line);
	
	for (tc = 1; tc <= TC; tc++)
	{
		if (tc != 1)
			cout << '\n';
		
		getline(cin, line);
		memset(cache, 0, sizeof cache);
		memset(input, 0, sizeof input);

		getline(cin, line);
		istringstream iss(line);
		iss >> N >> M;

		for (int n = 1; n <= N; n++)
		{
			getline(cin, line);
			iss = istringstream(line);

			int a;
			iss >> a;
			while (iss >> a)
			{
				input[n][a] = 1;
			}
		}

		if (!input[1][1])
		{
			cache[1][1] = 1;
		}

		for (int n = 1; n <= N; n++)
		{
			for (int m = 1; m <= M; m++)
			{
				if (!input[n][m - 1])
				{
					cache[n][m] += cache[n][m - 1];
				}

				if (!input[n-1][m])
				{
					cache[n][m] += cache[n-1][m];
				}
			}
		}

		cout << cache[N][M] << '\n';
	}



	return 0;
}