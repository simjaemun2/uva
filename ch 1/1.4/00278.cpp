#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define NUM_LENGTH 8

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc, T, M,N;
	char c;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> c >> M >> N;

		if (c == 'r' || c == 'Q')
		{
			cout << min(M, N) << '\n';
		}
		else if(c == 'K')
		{
			cout << ((M + 1) / 2) * ((N + 1) / 2) << '\n';
		}
		else
		{
			cout << ((M + 1) / 2) * ((N + 1) / 2)  + (M/2) * (N/2) << '\n';
		}
	}
	

	return 0;
}