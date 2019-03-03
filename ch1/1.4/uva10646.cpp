#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>


using namespace std;

#define NUM_CARDS 52
int X, Y;
string cards[NUM_CARDS];

int getValue(char c)
{
	if ('1' <= c && c <= '9')
		return c - '0';
	return 10;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	string card;
	int T, t;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		Y = 0;

		for (int i = 0; i < NUM_CARDS; i++)
		{
			cin >> cards[i];
		}

		int index = 0;
		for (int j = 0; j < 3; j++)
		{
			X = getValue(cards[index][0]);
			Y += X;
			index += 11 - X;
		}

		cout << "Case " << t << ": " << cards[index + Y - 1] << '\n';
	}

	return 0;
}