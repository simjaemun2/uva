#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>



using namespace std;

#define MAX_N 100000

char answer[MAX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	string line;
	getline(cin, line);
	int length = 1;
	while (true)
	{
		getline(cin, line);
		if (line[0] == '_')
			break;

		for (int i = 2; i <= 5; i++)
		{
			if (line[i] == 'o')
				answer[length - 1] += 1 << (8 - i);
		}

		for (int i = 7; i <= 9; i++)
		{
			if (line[i] == 'o')
				answer[length - 1] += 1 << (9 - i);
		}

		length++;
	}

	cout << answer;
	


	//A quick brown fox jumps over the lazy dog.

	return 0;
}