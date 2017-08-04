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
		int result = 0;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (result < a)
				result = a;
		}

		cout << "Case " << (tc + 1) << ": " << result << '\n';
	}

	return 0;
}