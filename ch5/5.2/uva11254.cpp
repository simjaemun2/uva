#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>

using namespace std;

int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N > 0)
	{
		int a;
		int n = sqrt(2 * N);
		for (; n >= 1; n--)
		{
			if ((2 * N - n*n + n) % (2 * n) == 0)
			{
				a = (2 * N - n*n + n) / (2 * n);
				break;
			}
		}

		cout << N << " = " << a << " + ... + " << a + n - 1 << '\n';
	}


	return 0;
}

