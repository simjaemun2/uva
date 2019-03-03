#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int N;
string line;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, line);

		int cnt = 0;

		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == 'M')
				cnt++;
			else if(line[j] == 'F')
				cnt--;
		}

		if (cnt == 0 && line.size() > 2)
			cout << "LOOP\n";
		else
			cout << "NO LOOP\n";

	}

	
	return 0;
}