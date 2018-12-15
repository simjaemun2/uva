#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>


using namespace std;

int M;
string s;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
			cout << '\n';

		cin >> M;

		int oudlers = 0;
		double sum = 0.0;

		for (int m = 0; m < M; m++)
		{
			cin >> s;

			if (s == "fool")//oudlers
			{
				sum += 4.5;
				oudlers++;
			}
			else
			{
				if (s == "king")
					sum += 4.5;
				else if (s == "queen")
					sum += 3.5;
				else if (s == "jack")
					sum += 1.5;
				else if (s == "knight")
					sum += 2.5;
				else if (s == "one" || s == "twenty-one")//oudlers
				{
					sum += 4.5;
					oudlers++;
				}
				else
				{
					sum += 0.5;
				}

				cin >> s >> s;
			}
		}

		int taker = 56;

		if (oudlers == 3)
			taker = 36;
		else if (oudlers == 2)
			taker = 41;
		else if (oudlers == 1)
			taker = 51;

		cout << "Hand " << '#' << tc << "\nGame ";

		if (taker > (int)sum)
			cout << "lost by " << taker - (int)sum << " point(s).\n";
		else
			cout << "won by " << (int)sum - taker << " point(s).\n";
	}

	return 0;
}
