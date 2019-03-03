#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX_N 10
string urls[MAX_N];
int v[MAX_N];

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> T;

	for (tc = 0; tc < T; tc++)
	{
		int maxV = -1;
		for (int i = 0; i < MAX_N; i++)
		{
			cin >> urls[i] >> v[i];
			if (maxV < v[i])
				maxV = v[i];
		}

		cout << "Case #" << (tc + 1) << ":\n";

		for (int i = 0; i < MAX_N; i++)
		{
			if (v[i] == maxV)
				cout << urls[i] << '\n';
		}
	}

	return 0;
}