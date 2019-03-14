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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_N = 20000;

int TC;
int N;

string S, T;


int main(int argc, char** argv)
{

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	std::ios::sync_with_stdio(false);

	while (cin >> S >> T)
	{
		int s = 0, t = 0;

		while (s < S.size() && t < T.size())
		{
			if (S[s] == T[t])
				s++;
			t++;
		}


		if (s == S.size())
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;

}