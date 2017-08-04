#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_SONG 16
int N;
string name[MAX_N];
/*Happy birthday to you! 
Happy birthday to you! 
Happy birthday to Rujia! 
Happy birthday to you!!!*/
char* song[MAX_SONG] = {
	"Happy","birthday","to","you"
	,"Happy","birthday","to","you"
	,"Happy","birthday","to","Rujia"
	,"Happy","birthday","to","you"
};

int getGCD(int a, int b)
{
	return b == 0 ? a : getGCD(b, a % b);
}

int main(int argc, char** argv)
{
	
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> name[i];

	int len = MAX_SONG;
	while (len < N)
		len += MAX_SONG;

	for (int i = 0; i < len; i++)
	{
		cout << name[i % N] << ": " << song[i%MAX_SONG] << '\n';
	}

	

	

	return 0;
}