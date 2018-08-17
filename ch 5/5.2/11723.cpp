#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

int R, N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;
	
	while (true)
	{
		cin >> R >> N;
		if (R == 0 && N == 0)
			return 0;

		cout << "Case " << tc++ << ": ";

		if (N * 27 < R)
			cout << "impossible\n";
		else
			cout << (R-1) / N << '\n';
	}

	
	return 0;
}

