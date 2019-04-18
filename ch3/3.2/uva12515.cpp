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


const int INF = 1000000;
const int MAX_M = 1000;
const int MAX_Q = 500;
const int MAX_L = 100;

int tc, TC;
int M, Q;

string movies[MAX_M];
string clip;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (cin >> M >> Q)
	{
		for(int m = 0; m < M; m++)
		{
			cin >> movies[m];
		}

		for (int q = 0; q < Q; q++)
		{
			cin >> clip;

			int minD = INF;
			int minIndex = -1;

			for (int m = 0; m < M; m++)
			{
				if (clip.size() <= movies[m].size())
				{
					int sizeDiff = movies[m].size() - clip.size();

					for (int k = 0; k <= sizeDiff; k++)
					{
						int d = 0;

						for (int i = 0, j = k; i < clip.size() && j < movies[m].size(); i++, j++)
						{
							if (clip[i] != movies[m][j])
								d++;
						}

						if (minD > d)
						{
							minD = d;
							minIndex = m;
						}
					}
				}
			}

			cout << minIndex+1 << '\n';
		}
	}
	
	return 0;
}
