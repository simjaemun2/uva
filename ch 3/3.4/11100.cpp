#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;

#define MAX_N 100000

int N;
int input[MAX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> N;
		if (!N)
			break;

		for (int n = 0; n < N; n++)
			cin >> input[n];
		
		input[N] = 0;
		
		sort(input, input + N);

		int cnt = 1;
		int K = 1;
		for (int n = 1; n <= N; n++)
		{
			if (input[n] == input[n - 1])
			{
				cnt += 1;
			}
			else
			{
				K = max(K, cnt);
				cnt = 1;
			}
		}
		cout << K << '\n';

		for (int i = 0; i < K; i++)
		{
			bool first = true;
			for (int j = i; j < N; j += K)
			{
				if (first)
					first = false;
				else
					cout << ' ';
				cout << input[j];
			}
			cout << '\n';
		}
	}

	return 0;
}

