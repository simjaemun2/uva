#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX_N 10000
int N,M;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	
	while (cin >> N)
	{
		vector<int> input(N);

		for (int i = 0; i < N; i++)
			cin >> input[i];
		cin >> M;
		
		sort(input.begin(), input.end());

		int a, b, diff = M * 2;

		for (int i = 0; i < N - 1 && input[i] <= M / 2; i++)
		{
			int x = M - input[i];
			
			if (binary_search(input.begin() + i + 1, input.end(), x)
				&& x - input[i] < diff)
				a = input[i], b = x;
		}

		cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
	}
	

	return 0;
}

