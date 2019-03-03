#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define MAX_N 100
#define NUM_CARD 13
#define NUM_COLOR 4

int shuffles[MAX_N + 1][NUM_CARD * NUM_COLOR + 1];
int card[NUM_CARD * NUM_COLOR + 1], temp[NUM_CARD * NUM_COLOR + 1];

int N;

char line[10];

char* colors[NUM_COLOR] = { "Clubs", "Diamonds", "Hearts", "Spades" };
char* nums[NUM_CARD] = { "Ace", "2","3","4","5","6","7","8","9","10","Jack","Queen","King" };

void shuffle(int n)
{
	for (int i = 1; i <= NUM_CARD * NUM_COLOR; i++)
	{
		temp[i] = card[shuffles[n][i]];
	}

	for (int i = 1; i <= NUM_CARD * NUM_COLOR; i++)
	{
		card[i] = temp[i];
	}
}

void printCards()
{
	for (int i = 1; i <= NUM_CARD * NUM_COLOR; i++)
	{
		cout << nums[card[i] % NUM_CARD] << " of " << colors[(card[i] - 1) / NUM_CARD] << '\n';
	}
}

int main(int argc, char** argv)
{
	int TC;
	cin >> TC;

	while (TC--)
	{
		cin >> N;

		for (int n = 1; n <= N; n++)
		{
			for (int i = 1; i <= NUM_CARD * NUM_COLOR; i++)
			{
				cin >> shuffles[n][i];
			}
		}

		for (int i = 1; i <= NUM_CARD * NUM_COLOR; i++)
		{
			card[i] = i;
		}

		cin.getline(line, 100);

		while (cin.getline(line, 100), line[0] != '\0')
		{
			shuffle(stoi(line));
		}

		printCards();

		if (TC)
			cout << '\n';
	}
	

	return 0;

}