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

#define MAX_N 5842

int N;

int cache[MAX_N + 1] = {0,1,};

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int t2 = 0;
	int t3 = 0;
	int t5 = 0;
	int t7 = 0;

	for (int i = 2; i <= MAX_N; i++)
	{
		while (cache[t2]*2 <= cache[i - 1])
			t2++;
		while (cache[t3]*3 <= cache[i - 1])
			t3++;
		while (cache[t5]*5 <= cache[i - 1])
			t5++;
		while (cache[t7]*7 <= cache[i - 1])
			t7++;

		int min1 = min(cache[t2] * 2, cache[t3] * 3);
		int min2 = min(cache[t5] * 5, cache[t7] * 7);
		cache[i] = min(min1, min2);
	}



	while (cin >> N, N)
	{
		cout << "The " << N;

		if (N % 10 == 1 && N%100 != 11)
			cout << "st humble number is ";
		else if (N % 10 == 2 && N%100 != 12)
			cout << "nd humble number is ";
		else if(N%10 == 3 && N%100 != 13)
			cout << "rd humble number is ";
		else
			cout << "th humble number is ";

		cout << cache[N] << ".\n";
	}
	
	return 0;
}

