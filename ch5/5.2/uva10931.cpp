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
#include <bitset>


using namespace std;

int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N, N)
	{
		int bits[33];
		int n = N;
		int size = 0;
		int cnt = 0;
		while (n)
		{
			bits[size] = n & 1;
			cnt += bits[size++];
			n >>= 1;
		}

		cout << "The parity of ";
		while (size)
			cout << bits[size-- - 1];
			
		cout << " is " << cnt << " (mod 2).\n";	
	}

	return 0;
}