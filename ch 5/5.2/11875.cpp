#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

#define MAX_N 11

int N;
int input[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for(int tc=1;tc<=T;tc++)
	{
		cin >> N;
		
		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		cout << "Case " << tc << ": " << input[N/2] << '\n';
	}

	
	return 0;
}

