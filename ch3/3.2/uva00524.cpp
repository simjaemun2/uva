#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 16

int N;
bool isNotPrime[MAX_N * 2 + 1];
int num[MAX_N];
bool checked[MAX_N];

void calPrimNum()
{
	isNotPrime[0] = isNotPrime[1] = true;

	for (int i = 2; i < MAX_N * 2 + 1; i++)
	{
		if (!isNotPrime[i])
		{
			for (int j = i*i; j < MAX_N * 2 + 1; j += i)
				isNotPrime[j] = true;
		}
	}
}



void rec(int n)
{
	if (n == N)
	{
		if (!isNotPrime[num[N - 1] + num[0]])
		{
			for (int i = 0; i < N; i++)
			{
				cout << num[i];
				if(i == N-1)
					cout << '\n';
				else
					cout << ' ';
					
			}
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (!checked[i])
		{
			checked[i] = true;
			num[n] = i + 1;
			if (!isNotPrime[num[n] + num[n - 1]])
				rec(n + 1);
			checked[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	calPrimNum();

	int tc = 1;
	cin >> N;
	while (true)
	{
		cout << "Case " << tc++ << ":\n";

		num[0] = 1;
		checked[0] = true;
		rec(1);
		//cout << '\n';

		if (!(cin >> N))
			break;
		cout << '\n';
	}

	return 0;
}

