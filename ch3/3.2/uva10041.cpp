#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 500;

int tc, TC;
int N;

int input[MAX_N];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		sort(input, input + N);

		int m = input[N / 2];

		int sum = 0;
		
		for (int n = 0; n < N; n++)
		{
			sum += abs(input[n] - m);
		}

		cout << sum << '\n';
	}


	
	return 0;
}

