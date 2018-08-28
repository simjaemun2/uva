#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <utility>

using namespace std;

#define MAX_N 10000

int N,K;

long input[MAX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> K, N != -1 && K != -1)
	{
		for (int i = 0; i <= N; i++)
			cin >> input[i];

		if (N < K)
		{
			cout << input[0];
			for (int i = 1; i <= N; i++)
				cout << ' ' << input[i];
			cout << '\n';
			continue;
		}

		for (int n = N; n >= K; n--)
		{
			input[n - K] -= input[n];
		}
		
		int d = K - 1;

		for (; d >= 0 && !input[d]; d--);

		if (d == -1)
		{
			cout << "0\n";
		}
		else
		{
			cout << input[0];
			for (int i = 1; i <= d; i++)
				cout << ' ' << input[i];
			cout << '\n';
		}	
	}
	
	

	return 0;

}