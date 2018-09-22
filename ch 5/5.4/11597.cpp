#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>



using namespace std;

#define MAX_N 1000000

int N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 1;
	while (cin >> N, N)
	{
		cout <<"Case " << tc++ << ": " <<  N / 2 << '\n';
	}

	return 0;
}