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
unsigned int N, L, U;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N, N)
	{
		LL sum = 0LL;
		LL prev = 0LL;
		for (int n = 0; n < N; n++)
		{
			LL a;
			cin >> a;
			sum += abs(prev + a);
			prev += a;
		}
		cout << sum << '\n';
	}
		
	
	return 0;
}