#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

#define MAX_I 20

int C,I,D,K;
int II[MAX_I + 1];

int main(int argc, char** argv)
{	
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		cin >> I;

		for (int i = 0; i <= I; i++)
			cin >> II[i];

		cin >> D >> K;

		int n = 1, d = D;

		while (d < K)
			d += ++n * D;

		long long int sum = 0;
		long long int mul = 1;
		
		for (int i = 0; i <= I; i++, mul *= n)
			sum += II[i] * mul;

		cout << sum << '\n';
	}


	return 0;
}