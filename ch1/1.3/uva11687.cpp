#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
string line;

#define PIVOT 10000000000

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> line;
		if (line[0] == 'E')
			return 0;

		int length = line.size();

		if (length >= 10)
		{
			cout << "4\n";
		}
		else if(length >= 2)
		{
			cout << "3\n";
		}
		else if (line == "1")
		{
			cout << "1\n";
		}
		else
		{
			cout << "2\n";
		}
	
		

		
	}
	
	return 0;
}