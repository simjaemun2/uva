#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;

#define MAX_N 20000
#define MAX_M 20000

int N, M;

int HEADS[MAX_N + 1];
int KNIGHTS[MAX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> N >> M;
		if (N + M == 0)
			break;

		for (int i = 0; i < N; i++)
			cin >> HEADS[i];
		for (int i = 0; i < M; i++)
			cin >> KNIGHTS[i];

		sort(HEADS, HEADS + N);
		sort(KNIGHTS, KNIGHTS + M);

		int n = 0, m = 0;
		int sum = 0;

		while (n < N && m < M)
		{
			if (HEADS[n] <= KNIGHTS[m])
			{
				sum += KNIGHTS[m];
				m++, n++;
			}
			else
			{
				m++;
			}
		}

		if (n < N)
			cout << "Loowater is doomed!\n";
		else
			cout << sum << '\n';

	}
				

	return 0;
}

