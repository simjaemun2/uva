#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

#define MAX_N 20000

int tc, TC;
int S;

int main(int argc, char** argv)
{
	/*
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		cin >> S;
		
		int startIndex = 1;
		int maxStartIndex = -1;
		int maxEndIndex = 0;
		int answer = 0;
		int sum = 0;


		for (int s = 2; s <= S; s++)
		{
			int a;
			cin >> a;

			sum += a;

			if (sum < 0)
			{
				sum = 0;
				startIndex = s;
			}

			if (sum >= answer)
			{
				if (sum > answer ||
					(sum == answer && (s - startIndex > maxEndIndex - maxStartIndex)))
				{
					maxEndIndex = s;
					maxStartIndex = startIndex;
				}


				answer = sum;
			}
		}

		/*
12 and 3
The nicest part of route 2 is between stops 3 and 9
Route 3 has no nice parts
	*/
		if (answer > 0)
		{
			cout << "The nicest part of route " << tc << " is between stops " << maxStartIndex << " and " << maxEndIndex << '\n';
			//cout << maxSum << '\n';
		}
		else
		{
			cout << "Route " << tc << " has no nice parts\n";
		}
		

	}

	return 0;
}