#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_P 25

int N,P,RESULT;
int input[MAX_P];

bool solve()
{
	for (int i = 0; i < 1 << P; i++)
	{
		int sum = 0;
		for (int j = 0; j < P; j++)
		{
			if (i & (1 << j))
				sum += input[j];
		}
		if (sum == N)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> P;
		
		for (int p = 0; p < P; p++)
		{
			cin >> input[p];
		}

		cout << (solve() ? "YES\n" : "NO\n");
	}
	

	return 0;
}

