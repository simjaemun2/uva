#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;

#define MAX_N 1000

int N;
int input[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc, T;
	cin >> T;

	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> input[i];

		int cnt = N == 1 ? 1 : 2;

		int sum = 1;

		for (int i = 1; i < N - 1; i++)
		{
			if (sum + input[i] < input[i + 1])
			{
				sum += input[i];
				cnt++;
			}
		}
		
		cout << cnt << '\n';
	}


	return 0;
}

