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
const int MAX_N = 100;

int tc, TC;
int N;

LL S2[MAX_N + 1];
LL R2[MAX_N + 1];
LL S3[MAX_N + 1];
LL R3[MAX_N + 1];
LL S4[MAX_N + 1];
LL R4[MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int n = 1; n <= MAX_N; n++)
	{
		LL combi = (n + 1)*n / 2;
		S2[n] = S2[n - 1] + n * n;
		S3[n] = S3[n - 1] + n * n * n;
		S4[n] = S4[n - 1] + n * n * n * n;
		R2[n] = combi * combi - S2[n];
		R3[n] = combi * combi * combi - S3[n];
		R4[n] = combi * combi * combi * combi - S4[n];
	}


	while (cin >> N)
	{
		cout << S2[N] << ' ' << R2[N] << ' ' << S3[N] << ' ' << R3[N] << ' ' << S4[N] << ' ' << R4[N] << '\n';
	}
	

	return 0;
}
