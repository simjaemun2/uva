#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>



using namespace std;

typedef long long int LL;

LL N;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 1;
	while (cin >> N, N)
	{
		LL l = 0, r = 100000000;
		while (l+1 < r)
		{
			LL m = (l + r) / 2;
			LL ngon = m * (m - 3) / 2;

			if (ngon < N)
				l = m;
			else
				r = m;
		}


		cout <<"Case " << tc++ << ": " << r << '\n';
	}

	return 0;
}