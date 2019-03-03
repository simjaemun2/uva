#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
string n1,n2;
double sum1, sum2;

double getSum(string& name)
{
	int sum = 0;
	for (int i = 0; i < name.size(); i++)
	{
		if ('a' <= name[i] && name[i] <= 'z')
			sum += name[i] - 'a' + 1;
		if ('A' <= name[i] && name[i] <= 'Z')
			sum += name[i] - 'A' + 1;
	}

	while (sum > 9)
	{
		int s = 0;
		while (sum > 0)
		{
			s += sum % 10;
			sum /= 10;
		}

		sum = s;
	}

	return (double)sum;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (getline(cin, n1))
	{
		getline(cin, n2);

		sum1 = getSum(n1);
		sum2 = getSum(n2);

		double result;

		if (sum1 > sum2)
			result = sum2 / sum1 * 100;
		else
			result = sum1 / sum2 * 100;

		printf("%.2lf %%\n", result);
	}

	
	return 0;
}