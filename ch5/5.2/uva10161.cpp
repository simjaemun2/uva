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

	while (cin >> N, N)
	{
		int L = ceil(sqrt(N));
		int C = L*L - L + 1;
		int X = L;
		int Y = L;
		if (L & 1)
		{
			if (N > C)
			{
				X -= N - C;

			}
			else
			{
				Y -= C - N;
			}
		}
		else
		{
			if (N > C)
			{
				Y -= N - C;
			}
			else
			{
				X -= C - N;
			}
		}

		cout << X << ' ' << Y << '\n';
	}
	


	return 0;
}

