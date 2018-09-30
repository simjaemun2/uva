#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <math.h>
#include <locale>

using namespace std;

#define MAX_N 80

string A, B;

int cache[MAX_N + 2][MAX_N + 2];
char moved[MAX_N + 2][MAX_N + 2];

int used;

int dp()
{
	int lenA = A.length();
	int lenB = B.length();

	for (int i = 1; i <= max(lenA, lenB); i++)
	{
		cache[i][0] = i;
		moved[i][0] = 'D';

		cache[0][i] = i;
		moved[0][i] = 'I';
	}

	cache[0][0] = 0;

	for (int i = 1; i <= lenA; i++)
	{
		for (int j = 1; j <= lenB; j++)
		{
			if (A[i-1] == B[j-1])
			{
				cache[i][j] = cache[i - 1][j - 1];
				moved[i][j] = 'M';
			}
			
			if (A[i - 1] != B[j - 1])
			{
				cache[i][j] = cache[i - 1][j - 1] + 1;
				moved[i][j] = 'R';
			}

			if (cache[i][j] >= cache[i - 1][j] + 1)
			{
				cache[i][j] = cache[i - 1][j] + 1;
				moved[i][j] = 'D';
			}

			if (cache[i][j] >= cache[i][j - 1] + 1)
			{
				cache[i][j] = cache[i][j - 1] + 1;
				moved[i][j] = 'I';
			}
		}
	}

	return cache[lenA][lenB];
}

void reconstruct(int a, int b, int cnt)
{
	if (a == 0 && b == 0)
		return;

	if (moved[a][b] == 'M')
	{
		reconstruct(a - 1, b - 1, cnt);
	}
	else if (moved[a][b] == 'R')
	{
		reconstruct(a - 1, b - 1, cnt - 1);
		cout << cnt << " Replace " << a - used << ',' << B[b - 1] << '\n';
	}
	else if (moved[a][b] == 'D')
	{
		reconstruct(a - 1, b, cnt - 1);
		cout << cnt << " Delete " << a - used++ << '\n';
	}
	else if (moved[a][b] == 'I')
	{
		reconstruct(a, b - 1, cnt - 1);
		cout << cnt << " Insert " << a - --used << ',' << B[b - 1] << '\n';
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	bool isFirst = true;

	while (cin >> A)
	{
		if (isFirst)
			isFirst = false;
		else
			cout << '\n';

		cin >> B;

		int answer = dp();

		cout << answer << '\n';

		used = 0;

		reconstruct(A.length(), B.length(), answer);	
	}
	
	return 0;
}
