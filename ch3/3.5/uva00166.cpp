#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
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
#include <sstream>
#include <functional>

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > II;

const int INF = 2000000000;
const int MAX_N = 20;
const int NUM_COINS = 6;
const int MAX_CHANGE = 1000;

int coins[] = { 1,2,4,10,20,40 };
int coin_nums[NUM_COINS];

int min_change[MAX_CHANGE + 1];
int possible_change[MAX_CHANGE + 1];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	for (int i = 1; i <= MAX_CHANGE; i++)
	{
		min_change[i] = INF;

		for (int j = 0; j < NUM_COINS; j++)
		{
			for (int k = 1; i - coins[j] * k >= 0; k++)
			{
				min_change[i] = min(min_change[i], min_change[i - coins[j] * k] + k);
			}
		}
	}

	while (true)
	{
		int sum = 0;

		for (int i = 0; i < NUM_COINS; i++)
		{
			cin >> coin_nums[i];
			sum += coins[i] * coin_nums[i];
		}

		if (!sum)
		{
			break;
		}

		int a, b;
		scanf("%d.%d", &a, &b);
		a = (a * 100 + b)/5;

		for (int i = 1; i <= sum; i++)
		{
			possible_change[i] = INF;
		}

		for (int i = 0; i < NUM_COINS; i++)
		{
			for (int k = sum; k >= 0; k--)
			{
				for (int j = 1; j <= coin_nums[i] && k - coins[i] * j >= 0; j++)
				{
					possible_change[k] = min(possible_change[k], possible_change[k - coins[i] * j] + j);
				}
			}
		}

		int answer = INF;

		for (int i = a; i <= sum; i++)
		{
			if (answer > possible_change[i])
			{
				answer = min(answer, possible_change[i] + min_change[i - a]);
			}		
		}

		printf("%3d\n", answer);
	}


	return 0;
}

