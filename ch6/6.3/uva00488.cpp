#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <math.h>

using namespace std;

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
		int H,F;
		cin >> H >> F;

		for (int f = 0; f < F; f++)
		{
			for (int i = 1; i <= H; i++)
			{
				for (int j = 0; j < i; j++)
				{
					cout << i;
				}
				cout << '\n';
			}

			for (int i = H - 1; i >= 1; i--)
			{
				for (int j = 0; j < i; j++)
				{
					cout << i;
				}
				cout << '\n';
			}
			
			if (f < F - 1)
				cout << '\n';
		}

		if (T > 0)
			cout << '\n';
	}

	return 0;
}
