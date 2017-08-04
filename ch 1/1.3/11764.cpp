#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

using namespace std;

int N;


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
		cin >> N;
		int lj = 0, hj = 0;
		int prev, cur;
		cin >> prev;
		for (int i = 1; i < N; i++)
		{
			cin >> cur;
			if (prev > cur)
				lj++;
			else if (prev < cur)
				hj++;
			prev = cur;
		}

		cout << "Case " << (tc + 1) << ": " << hj << " " << lj << '\n';
	}

	return 0;
}