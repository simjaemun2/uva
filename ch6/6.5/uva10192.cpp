#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define INF 1000000

string A, B;

int cache[MAX_N + 2][MAX_N + 2];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	int tc = 1;

	getline(cin, A);

	while (A[0] != '#')
	{
		getline(cin, B);

		int lenA = A.length();
		int lenB = B.length();

		memset(cache, 0, sizeof(cache));

		for (int i = 1; i <= lenA; i++)
		{
			for (int j = 1; j <= lenB; j++)
			{
				if (A[i - 1] == B[j - 1])
				{
					cache[i][j] = cache[i - 1][j - 1] + 1;
				}
				else
				{
					cache[i][j] = max(cache[i - 1][j],cache[i][j - 1]);
				}
			}
		}

		cout << "Case #" << tc++ << ": you can visit at most " << cache[lenA][lenB] << " cities.\n";


		getline(cin, A);
	}


	
	return 0;
}
