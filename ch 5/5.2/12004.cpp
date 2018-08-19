#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

#define MAX_N 500000

long long int N;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cout << "Case " << tc << ": ";
		cin >> N;

		long long int a = N*(N - 1);
		if (a % 4 == 0)
			cout << a / 4 << '\n';
		else if (a % 2 == 0)
			cout << a / 2<<'/'<<2 << '\n';
		else
			cout << a<< '/' << 4 << '\n';

	}
	


	return 0;
}

