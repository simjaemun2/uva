#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


const int MAX_DIGIT = 7;
int tc, TC;
int N;

int digit[MAX_DIGIT];
int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N, N)
	{
		cout << "Case " << ++tc << ": ";

		while (true)
		{
			int d = 0;
			int n = N++;
			int c[10] = { 0, };

			while (n)
			{
				digit[d] = n % 10;
				if (digit[d] == 0)
					break;

				c[digit[d]]++;
				if (c[digit[d++]] > 1)
					break;
				n /= 10;
			}

			if (n > 0)
				continue;

			int dd = d - 1;
			int cnt = 0;

			while (cnt <= d)
			{
				int t = dd;
				dd = (dd - (digit[dd] % d) + d) % d;
				cnt++;

				if (t == dd || !digit[dd])
				{
					break;
				}
					
				digit[t] = 0;
			}

			if (d == cnt && dd == d - 1)
			{
				cout << N - 1 << '\n';
				break;
			}
		}
	}
	


	
	return 0;
}

