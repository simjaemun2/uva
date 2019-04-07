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


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

int tc, TC;
int N;

const int MAX_N = 100;

int input[MAX_N][MAX_N];

int T, R, H;

const int MAX_TRH = 20;
const int INF = 2000000000;

int TT[MAX_TRH + 1];
int RR[MAX_TRH + 1];
int HH[MAX_TRH + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> T >> R >> H)
	{
		vector<pair<int, int> > vt, vr, vh;
		int a;
		for (int t = 1; t <= T; t++)
		{
			cin >> TT[t];
			
			for (int r = 1; r <= R; r++)
			{
				cin >> a;

				if (!a)
				{
					vt.push_back({t,r});
				}
			}
		}

		for (int r = 1; r <= R; r++)
		{
			cin >> RR[r];
			for (int h = 1; h <= H; h++)
			{
				cin >> a;
				
				if (!a)
				{
					vr.push_back({ r,h });
				}
			}
		}

		for (int h = 1; h <= H; h++)
		{
			cin >> HH[h];
			for (int t = 1; t <= T; t++)
			{
				cin >> a;
				
				if (!a)
				{
					vh.push_back({h,t});
				}
			}
		}

		int minP = INF;
		int mt, mr, mh;

		for (int t = 0; t < vt.size(); t++)
		{
			for (int r = 0; r < vr.size(); r++)
			{
				for (int h = 0; h < vh.size(); h++)
				{
					if (vt[t].second == vr[r].first
						&& vr[r].second == vh[h].first
						&& vh[h].second == vt[t].first
						&& TT[vt[t].first] + RR[vr[r].first] + HH[vh[h].first] < minP)
					{
						minP = TT[vt[t].first] + RR[vr[r].first] + HH[vh[h].first];
						mt = vt[t].first - 1;
						mr = vr[r].first - 1;
						mh = vh[h].first - 1;
					}
				}
			}
		}

		if (minP == INF)
		{
			cout << "Don't get married!\n";
		}
		else
		{
			cout << mt << ' ' << mr << ' ' << mh << ':' << minP << '\n';
		}
	}

	return 0;
}
