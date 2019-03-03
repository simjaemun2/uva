#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

#define MAX_N 10

int T, N, M;

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> T;
	
	bitset< (1 << MAX_N) > bs;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> N >> M;
		
		int a;
		bs.reset();

		for (int i = 0; i < M; i++)
		{
			cin >> a;
			bs.set(a - 1);
		}
		bs.flip();
		
		int cm = 1 << N;
		int result = 0;
		for (int i = 0; i < N; i++)
		{

			for (int m = 0; m < cm; m+=2)
			{
				if (bs.test(m) ^ bs.test(m + 1))
					result++;
				
				if (bs.test(m) || bs.test(m + 1))
					bs.set(m / 2);
				else
					bs.reset(m / 2);
			}
			cm /= 2;
		}

		cout << result << '\n';
	}




	return 0;
}