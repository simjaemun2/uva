#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

#define MAX_DRURATION 100

int duration, depreciation;
double downPay, amount;
double percentages[MAX_DRURATION + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while(true)
	{
		cin >> duration >> downPay >> amount >> depreciation;

		if (duration < 0)
			return 0;

		for (int i = 0; i < depreciation; i++)
		{
			int month;
			double percentage;
			cin >> month >> percentage;
			for (int j = month; j <= MAX_DRURATION; j++)
			{
				percentages[j] = percentage;
			}
		}

		double monthlyPay = amount / duration;
		double carWorth = (amount + downPay) * (1.0 - percentages[0]);
		int curMonth = 0;

		while (amount > carWorth)
		{
			amount -= monthlyPay;
			carWorth *= (1.0 - percentages[++curMonth]);
		}

		cout << curMonth << " month";
		if (curMonth != 1)
			cout << 's';
		cout << '\n';
	}

	
	

	return 0;
}