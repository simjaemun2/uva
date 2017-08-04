#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_N 20
int N,A;

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

		int minA = 100;
		int maxA = -1;

		for (int i = 0; i < N; i++)
		{
			cin >> A;
			if (A > maxA)
				maxA = A;
			if (A < minA)
				minA = A;
		}
		cout << 2 * (maxA - minA) << '\n';
	}

	return 0;
}