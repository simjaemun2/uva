#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N)
	{
		/*
		2 0 ~ 9
		4 00 ~ 99
		6 000 ~ 999
		8 0000 ~ 9999
		*/

		int bound = (int)pow(10, N / 2);

		for (int a = 0; a < bound; a++)
		{
			for (int b = 0; b < bound; b++)
			{
				if (a*bound + b == (a + b)*(a + b))
				{
					string sa = to_string(a);
					string sb = to_string(b);

					cout << string(N/2 - sa.length(), '0') << sa << string(N/2 - sb.length(), '0') << sb << '\n';
				}
			}
		}
	}
	
	return 0;
}

