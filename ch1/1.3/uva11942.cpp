#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cout << "Lumberjacks:\n";
	cin >> T;

	int a, b, c;

	for (tc = 0; tc < T; tc++)
	{
		cin >> a >> b;
		bool ordered = true;

		for (int i = 2; i < 10; i++)
		{
			cin >> c;
			if ((a - b)* (b - c) < 0)
				ordered = false;
			a = b;
			b = c;
		}
		
		if (ordered)
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}

	return 0;
}