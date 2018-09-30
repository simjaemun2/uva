#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

#define MAX_LEN 1000

string A;

int cache[MAX_LEN + 2][MAX_LEN + 2];

int dp(int left, int right)
{
	if (left == right)
		return 0;

	if (left + 1 == right)
		return 1;

	int& ret = cache[left][right];

	if (ret != -1)
		return ret;

	if (A[left] == A[right - 1])
		ret = 2 + dp(left + 1, right - 1);
	else
		ret = max(dp(left + 1, right), dp(left, right - 1));

	return ret;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	cin.ignore(100, '\n');
	while (T--)
	{
		getline(cin , A);

		if (A.length() == 0)
		{
			cout << "0\n";
			continue;
		}
			

		memset(cache, -1, sizeof(cache));

		cout << dp(0, A.length()) << '\n';
	}

	
	return 0;
}
