#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>


using namespace std;

string name;

int main(int argc, char** argv)
{
	int tc;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int sum = 0;
	string result;
	for (tc = 1; true; tc++)
	{
		cin >> name;
		if (name == "*")
			return 0;

		/*
		Case 1: Hajj-e-Akbar
		Case 2: Hajj-e-Asghar
		*/

		if (name == "Hajj")
			result = "Akbar";
		else
			result = "Asghar";

		cout << "Case " << tc << ": Hajj-e-" << result << '\n';

		
	}

	return 0;
}