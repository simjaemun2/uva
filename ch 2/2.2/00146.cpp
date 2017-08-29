#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

#define NUM_LENGTH 50
char input[NUM_LENGTH + 1];

void swap(int a, int b)
{
	char t = input[a];
	input[a] = input[b];
	input[b] = t;
}

//end = last index + 1
void reverse(int begin, int end)
{
	end--;

	while (begin < end)
		swap(begin++, end--);
}

//begin = 0, end = N
bool next_permutation(int begin, int end)
{
	if (begin == end || begin + 1 == end)
		return false;
	
	//last index
	int i = end - 1;

	while (true)
	{
		int j = i--;

		if (input[i] < input[j])
		{
			int k = end;
			
			while (!(input[i] < input[--k])); //skip

			swap(i, k);

			reverse(j, end);

			return true;
		}

		//reversed state
		if (i == begin)
		{
			reverse(begin, end);
			return false;
		}
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
		cin >> input;
		if (input[0] == '#')
			return 0;
		int length = strlen(input);

		if (next_permutation(0, length))
			cout << input << '\n';
		else
			cout << "No Successor\n";
	}


	return 0;
}