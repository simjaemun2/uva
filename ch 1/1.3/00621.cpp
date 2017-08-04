#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>


using namespace std;

string input;

int main(int argc, char** argv)
{
	int tc,T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		cin >> input;
		
		int len = input.size();

		if (input == "1" || input == "4" || input == "78")
			cout << "+\n";
		else if (input[len - 1] == '5' && input[len - 2] == '3')
			cout << "-\n";
		else if (input[0] == '9' && input[len - 1] == '4')
			cout << "*\n";
		else
			cout << "?\n";
		
	}

	return 0;
}