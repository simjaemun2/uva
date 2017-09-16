#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

using namespace std;

int N;

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		if (N == 0)
			return 0;

		int odd = 0;
		int even = 0;

		int i = 0;
		int index = 0;
		while (N)
		{
			if (N & 1)
			{
				index++;
				if(index & 1)
					odd |= 1 << i;
				else
					even |= 1 << i;
			}
			N >>= 1;
			i++;
		}
		cout << odd << ' ' << even << '\n';
	}
	

	return 0;
}