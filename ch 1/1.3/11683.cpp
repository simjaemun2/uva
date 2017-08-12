#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int A,C;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> A >> C;
		if (A +C == 0)
			return 0;
		
		int prev, cur;
		int result = 0;

		cin >> prev;

		for (int i = 1; i < C; i++)
		{
			cin >> cur;
			result += max(0, cur - prev);
			prev = cur;
		}
		
		result += A - prev;

		cout << result << '\n';
	}
	
	return 0;
}