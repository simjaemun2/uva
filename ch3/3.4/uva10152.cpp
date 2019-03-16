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
const int MAX_N = 1000;



int tc, TC;
int N;
string line;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	getline(cin, line);
	
	TC = stoi(line);

	for (tc = 1; tc <= TC; tc++)
	{
		getline(cin, line);

		N = stoi(line);
		vector<string> org(N), tur(N);

		for (int n = 0; n < N; n++)
		{
			getline(cin, org[n]);
		}

		for (int n = 0; n < N; n++)
		{
			getline(cin, tur[n]);
		}

		int i = N-1, j = N-1;

		for (; i >= 0; i--)
		{
			if (org[i] == tur[j])
			{
				j--;
			}
		}

		for (; j >= 0; j--)
		{
			cout << tur[j] << '\n';
		}
		cout << '\n';
	}
		
	return 0;

}