#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <sstream>
#include <bitset>
#include <iomanip>


using namespace std;

#define MAX_N 1000

int N;

double input[MAX_N+1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	

	while (cin >> N, N)
	{
		double sum = 0.0;
		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
			sum += input[i];
		}
			
		double m = sum / N;

		double neg = 0.0;
		double pos = 0.0;

		for (int i = 0; i < N; i++)
		{
			double diff = (double)(long)((input[i] - m) * 100.0) / 100.0;
			if (diff >= 0)
				pos += diff;
			else
				neg -= diff;
		}

		cout << '$';

		if (pos >= neg)
			cout << fixed << setprecision(2) << pos;
		else
			cout << fixed << setprecision(2) << neg;
		cout << '\n';
	}

	return 0;
}