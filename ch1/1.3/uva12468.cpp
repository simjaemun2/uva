#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int A,B;

int main(int argc, char** argv)
{
	
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (true)
	{
		cin >> A >> B;
		if (A == -1)
			return 0;

		if (A == B)
			cout << 0 << '\n';
		else if (A > B)
		{
			cout << min(A - B, B + 100 - A) << '\n';
		}
		else
		{
			cout << min(B - A, A + 100 - B) << '\n';
		}
	}

	

	return 0;
}