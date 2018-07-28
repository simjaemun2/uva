#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#define MAX_N 1000000
#define MAX_C 1000000

int N;
int input[MAX_N];

bool isPossible(int K)
{
	for (int n = 1; n <= N; n++)
	{
		int k = input[n] - input[n - 1];

		if (k > K)
			return false;
		if (k == K)
			K--;
	}

	return true;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T, tc;

	cin >> T;

		for (tc = 1; tc <= T; tc++)
		{
			cin >> N;

			int R = 0;
			int L = 1;

			for (int n = 1; n <= N; n++)
			{
				cin >> input[n];

				R = max(input[n] - input[n - 1], R);
			}

			R += 2;

			while (L <= R)
			{
				int m = (L + R) / 2;

				if (isPossible(m))
					R = m - 1;
				else
					L = m + 1;
			}

			cout << "Case " << tc << ": " << R + 1 << '\n';
		}

	return 0;
}

