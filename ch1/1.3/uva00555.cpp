#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define MAX_D 4
#define NUM_CARD 52

struct Node
{
	int color;
	int num;
};

Node nodes[MAX_D][NUM_CARD / MAX_D];
int stack[NUM_CARD / MAX_D];

char i2Player[MAX_D] = { 'S', 'W', 'N', 'E' };
char i2Color[MAX_D] = { 'C', 'D', 'S', 'H' };


bool compare(Node& a, Node& b)
{
	if (a.color == b.color)
	{
		return a.num > b.num;
	}

	return a.color > b.color;
}

bool notCompare(Node& a, Node& b)
{
	if (a.color == b.color)
	{
		return a.num < b.num;
	}

	return a.color < b.color;
}

void quicksort(Node arr[], int l, int r)
{
	register int top, i, j;
	top = -1;
	stack[++top] = l;
	stack[++top] = r;
	Node t;

	while (top >= 0)
	{
		r = stack[top--];
		l = stack[top--];

		if (l < r)
		{
			Node x = arr[(l + r) / 2];
			i = l, j = r;

			while (i <= j)
			{
				while (i < r && notCompare(arr[i], x))
					i++;
				while (compare(arr[j], x))
					j--;

				if (i <= j)
				{
					t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
					i++, j--;
				}
			}

			if (l < j)
			{
				stack[++top] = l;
				stack[++top] = j;
			}

			if (i < r)
			{
				stack[++top] = i;
				stack[++top] = r;
			}
		}
	}
}

int getStart(char c)
{
	int ret;
	switch (c)
	{
	case 'S':
		ret = 0;
		break;
	case 'W':
		ret = 1;
		break;
	case 'N':
		ret = 2;
		break;
	case 'E':
		ret = 3;
		break;
	}

	return ret;
}

int getColor(char c)
{
	int ret;
	switch (c)
	{
	case 'C':
		ret = 0;
		break;
	case 'D':
		ret = 1;
		break;
	case 'S':
		ret = 2;
		break;
	case 'H':
		ret = 3;
		break;
	}

	return ret;
}

int getNum(char c)
{
	if ('2' <= c && c <= '9')
		return c - '0';
	else if (c == 'T')
		return 10;
	else if (c == 'J')
		return 11;
	else if (c == 'Q')
		return 12;
	else if (c == 'K')
		return 13;
	else
		return 14;
}

char i2Num(int i)
{
	if (i < 10)
		return '0' + i;
	else if (i == 10)
		return 'T';
	else if (i == 11)
		return 'J';
	else if (i == 12)
		return 'Q';
	else if (i == 13)
		return 'K';
	else
		return 'A';
}

int main(int argc, char** argv)
{
	char start;

	while (cin >> start, start != '#')
	{
		char line[130];
		int player = getStart(start);
		
		cin >> line;
		cin >> &line[52];

		for (int i = 0; i < NUM_CARD; i++)
		{
			player = (player + 1) % MAX_D;

			nodes[player][i / MAX_D].color = getColor(line[i * 2]);
			nodes[player][i / MAX_D].num = getNum(line[i * 2 + 1]);
		}

		for (int d = 0; d < MAX_D; d++)
		{
			quicksort(nodes[d], 0, NUM_CARD / MAX_D - 1);

			cout << i2Player[d] << ':';

			for (int i = 0; i < NUM_CARD / MAX_D; i++)
			{
				cout << ' ' << i2Color[nodes[d][i].color] << i2Num(nodes[d][i].num);
			}

			cout << '\n';
		}
	}
	

	return 0;

}