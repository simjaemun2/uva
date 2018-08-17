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

int N,K;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	/*
	25 coconuts, 3 people and 1 monkey
30 coconuts, no solution
3121 coconuts, 5 people and 1 monkey
	
	*/

	while (cin >> N, N >= 0)
	{
		cout << N << " coconuts, ";
		int n = (int)sqrt(N) + 1;
		for (; n >= 2; n--)
		{
			bool isSolution = true;
			int d = N;
			for (int i = 1; i <= n && isSolution; i++)
			{
				if ((d - 1) % n == 0)
				{
					d = d - 1 - (d - 1) / n;
				}
				else
				{
					isSolution = false;
				}
			}

			if (isSolution && d%n == 0)
			{
				cout << n << " people and 1 monkey\n";
				break;
			}
		}

		if (n < 2)
			cout << "no solution\n";
	}

	return 0;
}

