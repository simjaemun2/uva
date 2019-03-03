#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>

using namespace std;

int N;
int counter[10];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		memset(counter, 0, sizeof(counter));
		
		for (int n = 1; n <= N; n++)
		{
			int s = n;
			while (s)
			{
				counter[s % 10]++;
				s /= 10;
			}
		}

		cout << counter[0];
		for (int i = 1; i <= 9; i++)
			cout << ' ' << counter[i];
		cout << '\n';
	}

	return 0;
}

