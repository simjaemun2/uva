#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;

#define MAX_N 1000

int N,D,R;
int morning[MAX_N];
int evening[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> N >> D >> R;

		if (!N)
			break;

		for (int i = 0; i < N; i++)
			cin >> morning[i];
		
		for (int i = 0; i < N; i++)
			cin >> evening[i];

		sort(morning, morning + N);
		sort(evening, evening + N);

		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (morning[i] + evening[N - i - 1] - D > 0)
				sum += morning[i] + evening[N - i - 1] - D;
		}

		cout << sum * R << '\n';
			

	}




	return 0;
}

