#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;

	char c;
	int y, x;

	while (TC--)
	{
		cin >> c >> y >> x;

		if (c == 'r')
		{
			cout << min(y, x) << '\n';
		}
		else if (c == 'k')
		{
			cout << ((y + 1) / 2) * ((x + 1) / 2)  + (y / 2) * (x / 2) << '\n';
		}
		else if (c == 'Q')
		{
			cout << min(y, x) << '\n';
		}
		else//K
		{
			cout << ((y + 1) / 2) * ((x + 1) / 2) << '\n';
		}
	}

	return 0;
}
