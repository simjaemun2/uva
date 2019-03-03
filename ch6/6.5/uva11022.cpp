#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

#define MAX_LEN 80

string A;

int cache[MAX_LEN + 2][MAX_LEN + 2];

int dp(int left, int right)
{
	if (left + 1 == right)
		return 1;

	int& ret = cache[left][right];

	if (ret != -1)
		return ret;

	ret = MAX_LEN * 2;

	

	for (int i = 1; i <= (right - left) / 2; i++)
	{
		if ((right - left) % i == 0)
		{
			string a = A.substr(left, i);
			
			int j;
			
			for (j = left + i; j < right; j += i)
			{
				if (a != A.substr(j, i))
					break;
			}

			if (j == right)
			{
				ret = min(ret, dp(left, left + i));
			}
				
		}
	}

	for (int i = left + 1; i < right; i++)
	{
		ret = min(ret, dp(left, i) + dp(i, right));
	}

	return ret;
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> A, A[0] != '*')
	{
		memset(cache, -1, sizeof(cache));
		cout << dp(0, A.length()) << '\n';
	}

	
	return 0;
}
