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

int K, N;

const int MAX_N = 500;
const int MAX_C = 6;

int cache[MAX_N + 1][MAX_C];
int prevc[MAX_N + 1][MAX_C][2];
int vtb[MAX_N + 1][MAX_C][2];

const char* dir[] = 
{
	"front",
	"back",
	"left",
	"right",
	"top",
	"bottom"
};


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	tc = 1;

	while (cin >> N, N)
	{
		if (tc != 1)
			cout << '\n';

		memset(cache, 0, sizeof cache);
		memset(prevc, -1, sizeof prevc);

		for (int n = 1; n <= N; n++)
		{
			for (int c = 0; c < MAX_C; c += 2)
			{
				int a, b;
				cin >> a >> b;
				vtb[n][c][0] = a;
				vtb[n][c][1] = b;
				vtb[n][c+1][0] = b;
				vtb[n][c+1][1] = a;
			}
		}

		int answer = 0;
		int answerN = 1;
		int answerC = 0;

		for (int n = 2; n <= N; n++)
		{
			for (int pn = 1; pn < n; pn++)
			{
				for (int c = 0; c < MAX_C; c++)
				{
					for (int pc = 0; pc < MAX_C; pc++)
					{
						if (vtb[n][c][0] == vtb[pn][pc][1]
							&& cache[n][c] < cache[pn][pc] + 1)
						{
							cache[n][c] = cache[pn][pc] + 1;
							prevc[n][c][0] = pn;
							prevc[n][c][1] = pc;

							if (answer < cache[n][c])
							{
								answer = cache[n][c];
								answerN = n;
								answerC = c;
							}
						}
					}
				}
			}
		}

		cout << "Case #" << tc++ << '\n' << answer + 1 << '\n';

		VI vn;
		VS vdir;

		while (true)
		{
			//cout << vtb[answerN][answerC][0] << ' ' << dir[answerC] << '\n';
			
			vn.push_back(answerN);
			vdir.push_back(dir[answerC]);

			if (prevc[answerN][answerC][0] == -1)
				break;

			int nextN = prevc[answerN][answerC][0];
			int nextC = prevc[answerN][answerC][1];

			answerN = nextN;
			answerC = nextC;
		}

		for (int i = vn.size() - 1; i >= 0; i--)
		{
			cout << vn[i] << ' ' << vdir[i] << '\n';
		}
	}


	return 0;
}