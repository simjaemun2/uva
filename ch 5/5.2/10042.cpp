#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>

using namespace std;

#define MAX_N 1000000000

bool isNotPrime[MAX_N + 1];
int N;
vector<int> primeNumber;

int getTN(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char** argv)
{
	int tc, T;

	std::ios::sync_with_stdio(false);

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int sqrtN = (int)sqrt(MAX_N);

	isNotPrime[0] = isNotPrime[1] = true;

	for (int i = 2; i <= sqrtN; i++)
	{
		if (!isNotPrime[i])
		{
			primeNumber.push_back(i);

			for (int j = i*i; j <= sqrtN; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}

	cin >> T;

	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		for (int n = N + 1; ; n++)
		{
			int sum = 0;
			int cnt = 0;
			int tmp = n;
			int i = 0;
			int sqrtn = (int)sqrt(n);
			
			while (tmp > 1 && i < primeNumber.size()&& primeNumber[i] <= sqrtn)
			{
				if (tmp%primeNumber[i] == 0)
				{
					tmp /= primeNumber[i];
					sum += getTN(primeNumber[i]);
					cnt++;
				}
				else
				{
					i++;
				}
			}
			
			if (tmp > 1)
			{
				cnt++;
				sum += getTN(tmp);
			}

			if (sum == getTN(n) && cnt > 1)
			{
				cout << n << '\n';
				break;
			}
				
		}
	}

	return 0;

}