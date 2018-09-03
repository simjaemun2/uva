#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>

using namespace std;

//TERM 3 IS 2/1
int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		int line = 0;
		int sum = 0;
		while (true)
		{
			sum += ++line;
			if (N <= sum)
				break;
		}
		

		if(line&1)
			cout << "TERM " << N << " IS " << sum - N + 1 << '/' << N - sum + line << '\n';
		else
			cout << "TERM " << N << " IS " << N - sum + line << '/' << sum - N + 1 << '\n';
			
	}

	return 0;
}