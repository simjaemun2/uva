#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cout << "KABIR\n";
	
	return 0;
}