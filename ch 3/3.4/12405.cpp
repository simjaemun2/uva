#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;

#define MAX_N 100

int N;
char input[MAX_N + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc, T;
	cin >> T;

	for (tc = 1; tc <= T; tc++)
	{
		cin >> N >> input;

		int i = 0;
		int cnt = 0;
		while (i < N)
		{
			if (input[i] == '.')
			{
				cnt++;
				i += 3;
			}
			else
			{
				i += 1;
			}
		}
		cout << "Case " << tc << ":" << " " << cnt << '\n';
	}




	return 0;
}

