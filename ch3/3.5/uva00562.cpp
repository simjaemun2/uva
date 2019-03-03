#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>

using namespace std;

typedef long long int LL;

const int MAX_N = 100;

int tc, TC;
int N;
int sum;
int input[MAX_N+1];
bool cache[50100];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;

		sum = 0;
		
		memset(cache, false, sizeof cache);

		cache[0] = true;

		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
			sum += input[i];
		}

		int mid = sum / 2;

		for (int i = 0; i < N; i++)
		{
			for (int j = mid; j >= input[i]; j--)
			{
				cache[j] |= cache[j - input[i]];
			}
		}

		for (int i = mid; i >= 0; i--)
		{
			if (cache[i])
			{
				cout << sum - 2 * i << '\n';
				break;
			}
		}

		
	}


	return 0;
}

