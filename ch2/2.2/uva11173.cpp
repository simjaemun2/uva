#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int N,a,b;

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cout << ((b >> 1) ^ b) << '\n';
	}

	return 0;
}