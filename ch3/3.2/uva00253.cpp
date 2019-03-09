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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > II;

const int INF = 2000000000;
const int MAX_LEN = 12;
const int HALF = 6;
const int ROTATE = 4;

char input[MAX_LEN + 1];

string org;
string rotated;
int zAxis[] = { 0,2,4,1,3,5};
int xAxis[] = { 4,0,2,3,5,1};
int yAxis[] = { 3,1,0,5,4,2};

string rotate(string& org, int axis[])
{
	char dst[HALF + 1];
	
	for (int i = 0; i < HALF; i++)
	{
		dst[i] = org[axis[i]];
	}

	dst[HALF] = 0;

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
				return "TRUE\n";
		}

		for (int z = 0; z < 4; z++)
		{
			rotated = rotate(rotated, zAxis);

			if (org == rotated)
				return "TRUE\n";
		}

		rotated = rotate(rotated, xAxis);

		if (org == rotated)
			return "TRUE\n";
	}
	

	return "FALSE\n";
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> input)
	{
		org = string(input, input + HALF);
		rotated = string(input + HALF);

		cout << check();
		
	}


	return 0;
}

