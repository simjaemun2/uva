#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <stack>

using namespace std;

#define MAX_N 20
#define MAX_M 10

int N,K,M;
int input[MAX_N];
int selected[MAX_M];
int value[MAX_M];

int countBit(int x)
{
	int c = 0;
	while (x)
	{
		c++;
		x &= (x-1);
	}
	return c;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	
	int tc = 1;

	while (true)
	{
		cin >> N >> K;

		if (N + K == 0)
			break;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		cin >> M;

		for (int i = 0; i < MAX_M; i++)
			selected[i] = 0;

		for (int m = 0; m < M; m++)
		{
			int T;
			cin >> T;
			for (int i = 0; i < T; i++)
			{
				int v;
				cin >> v;
				selected[m] |= 1 << (v - 1);
			}

			cin >> value[m];

		}

		int result = 0;
		int best = 0;
		for (int n = 1; n < (1 << N); n++)
		{
			if (countBit(n) == K)
			{
				int sum = 0;

				for (int i = 0; i < N; i++)
				{
					if (n & (1 << i))
						sum += input[i];
				}

				for (int i = 0; i < M; i++)
				{
					int t = selected[i] & n;
					if (t > 1)
						sum -= (countBit(t) - 1) * value[i];
				}

				if (sum > result)
				{
					best = n;
					result = sum;
				}
			}
		}

		cout << "Case Number  " << tc++ << '\n';
		cout << "Number of Customers: " << result << '\n';
		cout << "Locations recommended:";
		for (int i = 0; i < N; i++)
		{
			if (best & (1 << i))
				cout << ' ' << i+1;
		}
		cout << "\n\n";
		
	}
	

	return 0;
}

