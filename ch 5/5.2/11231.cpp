#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

#define MAX_N 500000

int N, M, C;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> M >> C, N)
	{
		if (C)
			cout << ((N-7)*(M-7)+1)/2 << '\n'; 
		else
			cout << (N - 7)*(M - 7) / 2 << '\n';
	}
	
	return 0;
}

