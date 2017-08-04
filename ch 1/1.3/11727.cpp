#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

int input[3];

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
		for (int i = 0; i < 3; i++)
			cin >> input[i];
		sort(input, input + 3);
		
		cout << "Case " << (tc+1) << ": " << input[1] << '\n';
	}

	return 0;
}