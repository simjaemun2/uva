#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_MONTH 12

int S, D, maxSum;
int checked[MAX_MONTH];

void rec(int n, int p)
{
	if (n == MAX_MONTH)
	{
		int sum = 0;
		for (int i = 0; i < MAX_MONTH; i++)
			sum += checked[i];
		maxSum = max(sum, maxSum);
		return;
	}

	checked[n] = p;

	if (n >= 4)
	{
		int pSum = 0;
		
		for (int i = n - 4; i <= n; i++)
			pSum += checked[i];
		
		if (pSum > 0)
			return;
	}

	rec(n + 1, S);
	rec(n + 1, D);
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> S >> D)
	{
		maxSum = -1;
		D *= -1;
		rec(0, S);

		if (maxSum <= 0)
			cout << "Deficit\n";
		else
			cout << maxSum << '\n';
	}

	return 0;
}

