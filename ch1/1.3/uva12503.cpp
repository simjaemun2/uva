#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX_N 100
int N;
string command;
int sameAs[MAX_N+1];

int main(int argc, char** argv)
{
	
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int T, tc;
	cin >> T;

	for (tc = 1; tc <= T; tc++)
	{
		int position = 0;
		int sameAsIndex;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> command;
			switch (command[0])
			{
			case 'L':
				position--;
				sameAs[i] = -1;
				break;
			case 'R':
				position++;
				sameAs[i] = 1;
				break;
			case 'S':
				cin >> command;
				cin >> sameAsIndex;
				sameAs[i] = sameAs[sameAsIndex];
				position += sameAs[i];
				break;
			}
		}

		cout << position << '\n';
	}

	

	return 0;
}