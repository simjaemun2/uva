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

		if (input.size() > 3)
			cout << 3 << '\n';
		else if (input[0] == 'o' && input[1] == 'n'
			|| input[1] == 'n' && input[2] == 'e'
			|| input[0] == 'o' && input[2] == 'e')
			cout << 1 << '\n';
		else
			cout << 2 << '\n';
	
		
	}

	return 0;
}