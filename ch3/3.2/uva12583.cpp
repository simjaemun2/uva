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

const int INF = 2000000000;
const int MAX_N = 24;

int tc, TC;
int N,K;
string s;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> K >> s;

		int answer = 0;

		for (int i = 1; i < N; i++)
		{
			set<char> se;

			for (int j = i - 1; j >= 0 && i - j <= K; j--)
			{
				if (s[i] == s[j])
				{
					if (se.find(s[j]) == se.end())
					{
						answer++;
						se.insert(s[j]);
					}
				}
			}
		}

		cout << "Case " << tc << ": " << answer << '\n';
	}

	
	
	return 0;
}