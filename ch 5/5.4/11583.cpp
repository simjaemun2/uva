#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>



using namespace std;

typedef long long int LL;

LL N,M;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> M >> N, N != 0LL && M != 0LL)
	{
		
		if (N == 1LL && M == 1LL)
		{
			cout << 0 << '\n';
			continue;
		}
		

		if (M > N)
		{
			LL t = M;
			M = N;
			N = t;
		}

		LL result = N*M*(N + M - 2) + (N - M + 1)*M*(M - 1) * 2 + M*(M-1)*(M-2)*4/3;

		cout << result << '\n';
	}

	return 0;
}