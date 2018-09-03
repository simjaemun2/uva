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

int N;
string line;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (getline(cin, line))
	{
		
		istringstream iss(line);
		vector<int > coefficients;
		while (iss >> N)
			coefficients.push_back(N);

		getline(cin, line);
		iss = istringstream(line);

		iss >> N;

		while (true)
		{
			double sum = 0;
			for (int i = 0; i < coefficients.size(); i++)
			{
				sum += coefficients[coefficients.size() - i - 1] * pow(N, i);
			}
			cout << (int)sum;

			if (iss >> N)
				cout << ' ';
			else
				break;
		}
		cout << '\n';
	}

	return 0;
}