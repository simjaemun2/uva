#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

#define MAX_LINE 200
#define MAX_I_LEN 10

string A;

typedef long long int LL;

LL imax = (LL) std::numeric_limits<int>::max();

LL cache[MAX_LINE + 1];

LL dp(int start)
{
	if (start == A.length())
	{
		return 0LL;
	}

	LL& ret = cache[start];

	if (ret != -1LL)
		return ret;

	int len = MAX_I_LEN;
	if (len > A.length() - start)
		len = A.length() - start;

	for (int i = 1; i <= len; i++)
	{
		if (stoll(A.substr(start, i)) <= imax)
		{
			ret = max(ret, stoll(A.substr(start, i)) + dp(start + i));
		}
	}

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

	while (T--)
	{
		cin >> A;
		if (A.length() <= 10 && stoll(A) <= imax)
		{
			cout << stoll(A) << '\n';
			continue;
		}
	
		memset(cache, -1, sizeof(cache));

		cout << dp(0) << '\n';
	}

	
	return 0;
}
