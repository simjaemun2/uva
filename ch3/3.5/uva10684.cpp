#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bitset>


using namespace std;

#define MAX_N 10000

typedef long long int LLI;

int input[MAX_N + 1];
int cache[MAX_N + 1];
int N;
int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (true)
	{
		cin >> N;
		if (!N)
			return 0;

		for (int i = 1; i <= N; i++)
		{
			cin >> input[i];
//			cache[i] = input[i] + input[i - 1];
		}
		
		int ret = -1;

		for (int i = 1; i <= N; i++)
		{
			if (input[i] > 0)
			{
				int sum = 0;

				for (int j = i; j <= N; j++)
				{
					sum += input[j];
					ret = max(sum, ret);
				}

			}
		}

		if (ret <= 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << ret << ".\n";

		
		

	}


	
				

	return 0;
}

