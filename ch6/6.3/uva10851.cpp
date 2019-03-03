#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>



using namespace std;

#define MAX_N 80
#define MAX_ROW 10

int N;
char answer[MAX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;

	string line;

	while (N--)
	{
		memset(answer, 0, sizeof(answer));

		cin >> line;
		
		int M = line.length() - 2;
		
		int shift = 1;

		for (int i = 1; i < MAX_ROW - 1; i++)
		{
			cin >> line;
			for (int j = 1; j <= M; j++)
			{
				if (line[j] == '\\')
				{
					answer[j-1] += shift;
				}
			}
			shift <<= 1;
		}
			
		cin >> line;

		cout << answer << '\n';
	}
	

	return 0;
}