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
int N;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		vector<string> oldv, newv;

		for (int i = 0; i < 10000; i++)
		{
			string old = to_string(i);
			oldv.push_back(string(4 - old.length(), '0').append(old));
		}

		cin >> N;
		
		for (int n = 0; n < N; n++)
		{
			string c1, c2;
			cin >> c1 >> c2;

			int correct = c2[0] - '0';
			int mis = c2[2] - '0';
			

			for (string s : oldv)
			{
				int c = 0;
				int m = 0;

				int tmp1[4];
				int tmp2[4];

				for (int i = 0; i < 4; i++)
				{
					tmp1[i] = s[i];
					tmp2[i] = c1[i];

					if (s[i] == c1[i])
					{
						tmp1[i] = 0;
						tmp2[i] = 1;
						c++;
					}
				}


				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (tmp1[i] == tmp2[j])
						{
							m++;
							tmp1[i] = 0;
							tmp2[j] = 1;
							break;
						}
					}
				}


				if (correct == c && mis == m)
				{
					newv.push_back(s);
				}
			}

			oldv.swap(newv);
			newv.clear();
		}

		if (oldv.size() > 1)
		{
			cout << "indeterminate\n";
		}
		else if (oldv.size() == 1)
		{
			cout << oldv[0] << '\n';
		}
		else
		{
			cout << "impossible\n";
		}
	}
	
	return 0;
}
