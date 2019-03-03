#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int N;
string line;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> N;
		if (N == 0)
			return 0;

		cin >> line;

		int lr = -1;
		int ld = -1;
		int mind = 20000000;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == 'Z')
			{
				mind = 0;
				break;
			}
			
			if (line[i] == 'R')
			{
				lr = i;
				if (ld > -1 && mind > lr - ld)
					mind = lr - ld;
			}
			else if (line[i] == 'D')
			{
				ld = i;
				if (lr > -1 && mind > ld - lr)
					mind = ld - lr;
			}
		}

		cout << mind << '\n';
	}
	
	return 0;
}