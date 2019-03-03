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

int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		int length = to_string(N).size();
		double l, r;

		while (true)
		{
			length++;

			l = log2(N) + length * log2(10);
			r = log2(N+1) + length * log2(10);

			if ((int)l < (int)r)
				break;
		}
		cout << (int)r << '\n';
	}

	return 0;
}