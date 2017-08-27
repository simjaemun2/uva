#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 3000

int N;
int input[MAX_N];
bool isJolly;
bool diff[MAX_N];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N)
	{
		isJolly = true;
		for (int i = 1; i < N; i++)
			diff[i] = false;


		cin >> input[0];
		for (int i = 1; i < N; i++)
		{
			cin >> input[i];
			int d = abs(input[i] - input[i - 1]);
			if (d >= N || d == 0)
				isJolly = false;
			else
				diff[d] = true;
		}

		if (isJolly)
		{
			for (int i = 1; i < N; i++)
			{
				if (!diff[i])
				{
					isJolly = false;
					break;
				}
			}
		}

		if (isJolly)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
			

	

	return 0;
}