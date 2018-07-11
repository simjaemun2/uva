#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <stack>

using namespace std;

#define MAX_N 5000

int N, A;
int input[MAX_N + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;
	
	for (int n = 0; n < N; n++)
	{
		int cnt = 0;
		cin >> A;

		for (int i = 0; i < A; i++)
		{
			cin >> input[i];

			for (int j = 0; j < i; j++)
			{
				if (input[i] >= input[j])
				{
					cnt++;
				}
			}
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}