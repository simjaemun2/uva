#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#define MAX_N 1000
#define MAX_C 1000000

int N, M;
int input[MAX_N];

bool isPossible(int capacity)
{
	int m = 1;
	int c = 0;

	for (int n = 0; n < N; n++)
	{
		if (input[n] > capacity)
			return false;

		c += input[n];

		if (c > capacity)
		{
			c = input[n];
			m++;
		}

		if (m > M)
			return false;
	}

	return true;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	double th = pow(10, -10);

	while (cin >> N >> M)
	{
		int l = 1;
		int r = 0;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
			r += input[n];
		}

		r++;

		while (l <= r)
		{
			int m = (l + r) / 2;
			if (isPossible(m))
				r = m-1;
			else
				l = m+1;
		}
		cout << r+1 << '\n';
	}
	

	return 0;
}

