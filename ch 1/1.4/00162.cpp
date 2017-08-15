#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_CARD 52

int getCoverNum(char c)
{
	switch (c)
	{
	case 'A':
		return 4;
	case 'K':
		return 3;
	case 'Q':
		return 2;
	case 'J':
		return 1;
	}

	return 0;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (true)
	{
		deque<char> player[2];
		deque<char> deck;

		for (int i = 1; i <= MAX_CARD; i++)
		{
			string card;
			cin >> card;
			if (card[0] == '#')
				return 0;
			player[i % 2].push_front(card[1]);
		}

		int turn = 1;
		int lastFace = -1;
		int cn = 0;
		while (!player[turn].empty())
		{
			char card = player[turn].front();
			player[turn].pop_front();
			deck.push_front(card);

			if (getCoverNum(card))
			{
				lastFace = turn;
				cn = getCoverNum(card) + 1;
				turn = (turn + 1) % 2;
			}

			if (cn)
			{
				cn--;
				if (!cn)
				{
					while (!deck.empty())
					{
						player[lastFace].push_back(deck.back());
						deck.pop_back();
					}

					turn = lastFace;
				}
			}
			else
			{
				turn = (turn + 1) % 2;
			}
		}
		int winner = (turn + 1) % 2;

		printf("%d%3d\n", winner + 1, player[winner].size());
	}
	
	return 0;
}