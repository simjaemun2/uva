#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>


using namespace std;

#define MAX_CARD 13

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	string card;

	map<char, int> map_suit_to_index;
	map_suit_to_index['S'] = 0;
	map_suit_to_index['H'] = 1;
	map_suit_to_index['D'] = 2;
	map_suit_to_index['C'] = 3;

	char index_to_suit[] = "SHDC";

	while (cin >> card)
	{
		bool a[4], k[4], q[4], j[4], t[4];
		int count[4], points = 0, specialPoints = 0;

		for (int i = 0; i < 4; i++)
		{
			a[i] = k[i] = q[i] = j[i] = t[i] = false;
			count[i] = 0;
		}

		for (int i = 0; i < MAX_CARD; i++)
		{
			if (i > 0)
				cin >> card;

			int suit_index = map_suit_to_index[card[1]];
			
			switch (card[0])
			{
			case 'A':
				a[suit_index] = true;
				points += 4;
				break;
			case 'K':
				k[suit_index] = true;
				points += 3;
				break;
			case 'Q':
				q[suit_index] = true;
				points += 2;
				break;
			case 'J':
				j[suit_index] = true;
				points += 1;
				break;
			}
			
			count[suit_index]++;
		}

		for (int i = 0; i < 4; i++)
		{
			if (a[i])
				t[i] = true;
			
			if (k[i])
			{
				if (count[i] < 2)
					points--;
				else
					t[i] = true;
			}
			
			if (q[i])
			{
				if (count[i] < 3)
					points--;
				else
					t[i] = true;
			}
			
			if (j[i] && count[i] < 4)
				points--;
			

			if (count[i] == 2)
				specialPoints++;
			else if (count[i] < 2)
				specialPoints += 2;
		}

		if (t[0] && t[1] && t[2] && t[3] && points >= 16)
			cout << "BID NO-TRUMP\n";
		else if (points + specialPoints >= 14)
		{
			int index = 0;

			for (int i = 1; i < 4; i++)
			{
				if (count[i] > count[index])
				{
					index = i;
				}
			}

			cout << "BID " << index_to_suit[index] << '\n';
		}
		else
		{
			cout << "PASS\n";
		}
	}
	
	return 0;
}