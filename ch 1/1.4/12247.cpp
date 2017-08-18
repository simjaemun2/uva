#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define NUM_CARDS 52

int princess[3];
int prince[2];
bool selected[NUM_CARDS + 1];

void getValue(int start, int& result)
{
	for (int i = start; i <= NUM_CARDS && i < result; i++)
	{
		if (!selected[i])
			result = i;
	}
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		int result = 53;

		cin >> princess[0] >> princess[1] >> princess[2] >> prince[1] >> prince[0];
		

		if (princess[0] == 0)
			return 0;

		sort(princess, princess + 3);
		sort(prince, prince + 2);
		

		for (int i = 1; i <= NUM_CARDS; i++)
			selected[i] = false;

		selected[princess[0]] = selected[princess[1]] = selected[princess[2]] = selected[prince[1]] = selected[prince[0]] = true;

		if (prince[0] > princess[2])
			getValue(1, result);
		
		if (prince[1] > princess[2])
			getValue(princess[2], result);
		
		if (prince[0] > princess[1])
			getValue(princess[1], result);

		if (result == 53)
			result = -1;

		cout << result << '\n';
	}
	

	return 0;
}