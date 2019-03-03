#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

string line;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> line;
		
		if (line.compare("0") == 0)
			break;
		
		int shift = 2;
		int sum = 0;
		for (int i = line.size() - 1; i >= 0; i--)
		{
			sum += (line[i] - '0') * (shift - 1);
			shift <<= 1;
		}
		cout << sum << '\n';
	
	}

	return 0;
}