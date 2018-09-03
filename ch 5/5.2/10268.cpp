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

using namespace std;

long long int N;
string line;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		getline(cin, line);
		getline(cin, line);
		istringstream iss(line);

		int n;
		vector<int > coefficients;
		while (iss >> n)
			coefficients.push_back(n);

		long long int sum = 0;

		for (int i = 0; i < coefficients.size() - 1; i++)
		{
			sum = sum * N + coefficients[i] * (coefficients.size() - i - 1);
		}

		cout << sum << '\n';
	
	}

	return 0;
}