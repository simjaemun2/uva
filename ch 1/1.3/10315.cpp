#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define NUM_CARD 13
#define NUM_COLOR 4

enum Rank{
	HC,
	PAIR,
	TWOPAIR,
	THREE,
	STRAIGHT,
	FLUSH,
	FULLHOUSE,
	FOUR,
	SF
};

struct Card {
	char suit;
	int value;
};

struct Player {
	Card cards[5];
	Rank rank;
	int suitCnt[4];
	int highest[5];
};


Card setCard(string& s)
{
	Card newCard;
	newCard.suit = s[1];

	if ('2' <= s[0] && s[0] <= '9')
		newCard.value = s[0] - '1';
	else if (s[0] == 'T')
		newCard.value = 9;
	else if (s[0] == 'J')
		newCard.value = 10;
	else if (s[0] == 'Q')
		newCard.value = 11;
	else if (s[0] == 'K')
		newCard.value = 12;
	else//ACE
		newCard.value = 13;

	return newCard;
}

bool compare(Card& a, Card& b)
{
	if (a.value == b.value)
		return a.suit < b.suit;
	return a.value < b.value;
}

bool isFlush(Player& p)
{
	int i;

	for (i = 0; i < 4; i++)
		if (p.suitCnt[i] == 5)
			break;

	if (i == 4)
		return false;

	for (int i = 4; i >= 0; i--)
	{
		p.highest[i] = p.cards[i].value;
	}

	return true;
}

bool isStraight(Player& p)
{
	for (int i = 0; i < 4; i++)
		if ((p.cards[i].value + 1) % 13 != p.cards[i + 1].value % 13)
			return false;

	for (int i = 4; i >= 0; i--)
	{
		p.highest[i] = p.cards[i].value;
	}
	return true;
}

bool isFour(Player& p)
{
	int i;

	for (i = 1; i < 4; i++)
		if (p.cards[i].value != p.cards[i + 1].value)
			break;
	if (i == 4)
	{
		for (int i = 4; i >= 1; i--)
		{
			p.highest[i] = p.cards[i].value;
		}
		
		p.highest[0] = p.cards[0].value;
		
		return true;
	}

	for (i = 0; i < 3; i++)
		if (p.cards[i].value != p.cards[i + 1].value)
			break;

	if (i == 3)
	{
		for (int i = 3; i >= 0; i--)
		{
			p.highest[i+1] = p.cards[i].value;
		}

		p.highest[0] = p.cards[4].value;
		return true;
	}

	return false;
}

bool isFull(Player& p)
{
	if (p.cards[3].value == p.cards[4].value)
	{
		if (p.cards[2].value == p.cards[3].value)
		{
			if (p.cards[0].value == p.cards[1].value)
			{
				for (int i = 4; i >= 2; i--)
				{
					p.highest[i] = p.cards[i].value;
				}
				for (int i = 1; i >= 0; i--)
				{
					p.highest[i] = p.cards[i].value;
				}

				return true;
			}
		}
		else if (p.cards[0].value == p.cards[1].value && p.cards[1].value == p.cards[2].value)
		{
			for (int i = 2; i >= 0; i--)
			{
				p.highest[i+2] = p.cards[i].value;
			}
			for (int i = 4; i >= 3; i--)
			{
				p.highest[i-3] = p.cards[i].value;
			}
			return true;
		}
	}

	return false;
}

bool isThree(Player& p)
{
	for (int i = 4; i >= 2; i--)
	{
		int j;
		for (j = 0; j < 3; j++)
			if (p.cards[i - j].value != p.cards[i - j - 1].value)
				break;
		if (j == 3)
		{
			p.highest[4] = p.highest[3] = p.highest[2] = p.cards[i].value;
			if (i == 4)
			{
				p.highest[1] = p.cards[1].value;
				p.highest[0] = p.cards[0].value;
			}
			else if (i == 3)
			{
				p.highest[1] = p.cards[4].value;
				p.highest[0] = p.cards[0].value;
			}
			else
			{
				p.highest[1] = p.cards[4].value;
				p.highest[0] = p.cards[3].value;
			}

			return true;
		}
	}
	return false;
}

bool isTwo(Player& p)
{
	int cnt = 0;
	
	int idx[2] = {-1,-1};


	for (int i = 4; i > 0; i--)
	{
		if (p.cards[i].value == p.cards[i - 1].value)
		{
			idx[cnt++] = i;
		}
	}
		

	if (cnt != 2)
		return false;

	p.highest[4] = p.highest[3] = p.cards[idx[0]].value;
	p.highest[2] = p.highest[1] = p.cards[idx[1]].value;

	for (int i = 4; i >= 0; i--)
	{
		if (i != idx[0] && i != idx[0] - 1 && i != idx[1] && i != idx[1] - 1)
		{
			p.highest[0] = p.cards[i].value;
			break;
		}
	}

	return true;
}

bool isOne(Player& p)
{
	int idx = -1;


	for (int i = 4; i > 0; i--)
	{
		if (p.cards[i].value == p.cards[i - 1].value)
		{
			idx = i;
			break;
		}
	}


	if (idx == -1)
		return false;

	p.highest[4] = p.highest[3] = p.cards[idx].value;

	int hCnt = 2;

	for (int i = 4; i >= 0; i--)
	{
		if (i != idx && i != idx - 1)
		{
			p.highest[hCnt--] = p.cards[i].value;
		}
	}

	return true;
}


void setRank(Player& p)
{
	sort(p.cards, p.cards + 5, compare);

	//set suit cnt
	for (int i = 0; i < 4; i++)
		p.suitCnt[i] = 0;

	for (int i = 0; i < 5; i++)
	{
		if (p.cards[i].suit == 'C')
			p.suitCnt[0]++;
		else if(p.cards[i].suit == 'D')
			p.suitCnt[1]++;
		else if (p.cards[i].suit == 'H')
			p.suitCnt[2]++;
		else
			p.suitCnt[3]++;
	}

	if (isFlush(p) && isStraight(p))
	{
		p.rank = SF;
		return;

		
	}

	if (isFour(p))
	{
		p.rank = FOUR;
		return;
	}

	if (isFull(p))
	{
		p.rank = FULLHOUSE;
		return;
	}

	if (isFlush(p))
	{
		p.rank = FLUSH;
		return;
	}

	if (isStraight(p))
	{
		p.rank = STRAIGHT;
		return;
	}

	if (isThree(p))
	{
		p.rank = THREE;
		return;
	}

	if (isTwo(p))
	{
		p.rank = TWOPAIR;
		return;
	}

	if (isOne(p))
	{
		p.rank = PAIR;
		return;
	}

	p.rank = HC;

	for (int i = 4; i >= 0; i--)
	{
		p.highest[i] = p.cards[i].value;
	}
}

int main(int argc, char** argv)
{
	string s;
	Player player[2];

	while (cin >> s)
	{
		player[0].cards[0] = setCard(s);

		for (int i = 1; i < 10; i++)
		{
			cin >> s;
			player[i/5].cards[i%5] = setCard(s);
		}

		setRank(player[0]);
		setRank(player[1]);

		if (player[0].rank == player[1].rank)
		{
			int i;

			for (i = 4; i >= 0; i--)
			{
				if (player[0].highest[i] > player[1].highest[i])
				{
					cout << "Black wins.\n";
					break;
				}						
				else if (player[0].highest[i] < player[1].highest[i])
				{
					cout << "White wins.\n";
					break;
				}
						
			}

			if(i == -1)
				cout << "Tie.\n";
		}
		else if (player[0].rank > player[1].rank)
		{
			cout << "Black wins.\n";
		}
		else
		{
			cout << "White wins.\n";
		}
	}
	

	return 0;

}