#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>
#include <map>
#include <limits.h>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;


const int INF = 2000000000;
const int MAX_N = 6;


int tc, TC;

string org;
string rotated;
int xAxis[] = { 4, 2, 0, 3, 1, 5 };
int zAxis[] = { 0, 1, 5, 2 ,3 ,4 };
int yAxis[] = { 3, 5 ,2 ,1 ,4 ,0 };

char dst[MAX_N + 1];

string rotate(string& org, int axis[])
{
	

	for (int i = 0; i < MAX_N; i++)
	{
		dst[i] = org[axis[i]];
	}

	dst[MAX_N] = 0;

	return string(dst);
}

string check()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			rotated = rotate(rotated, yAxis);

			if (org == rotated)
				return "Equal\n";
		}

		for (int z = 0; z < 4; z++)
		{
			rotated = rotate(rotated, zAxis);

			if (org == rotated)
				return "Equal\n";
		}

		rotated = rotate(rotated, xAxis);

		if (org == rotated)
			return "Equal\n";
	}


	return "Not Equal\n";
}


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		
		cin >> org >> rotated;
		cout << check();
	}

	return 0;
}
