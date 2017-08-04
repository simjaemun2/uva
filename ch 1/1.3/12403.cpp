#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>


using namespace std;

int money;
string command;

int main(int argc, char** argv)
{
	int tc,T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	
	cin >> T;
	int sum = 0;
	for (tc = 1; tc <= T; tc++)
	{
		cin >> command;

		if (command == "donate")
		{
			cin >> money;
			sum += money;
		}
		else
		{
			cout << sum << '\n';
		}
	}

	return 0;
}