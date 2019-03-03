#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

const int MOD = 40;
const int D = 9;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int a, b, c, d;

	while (true)
	{
		cin >> a >> b >> c >> d;

		if (a + b + c + d == 0)
			break;

		int result = 1080;

		cout << 1080 + ((a - b + MOD) % MOD + (c - b + MOD) % MOD + (c - d + MOD) % MOD) * D << '\n';
	}

	return 0;
}