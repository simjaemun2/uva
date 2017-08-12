#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX_BYTE 100
#define MOD 256

string line;
int N;
int memory[MAX_BYTE];
char getHex[] = "0123456789ABCDEF";

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N;

	for(int i=1; i<=N; i++)
	{
		for (int j = 0; j < MAX_BYTE; j++)
			memory[j] = 0;

		cin >> line;
		cout << "Case " << i << ':';
		
		int index = 0;

		for (int j = 0; j < line.size(); j++)
		{
			switch (line[j])
			{
			case '>':
				index = (index + 1) % MAX_BYTE;
				break;
			case '<':
				index = (index - 1 + MAX_BYTE) % MAX_BYTE;
				break;
			case '+':
				memory[index] = (memory[index] + 1) % MOD;
				break;
			case '-':
				memory[index] = (memory[index] - 1 + MOD) % MOD;
				break;
			}
		}

		for (int j = 0; j < MAX_BYTE; j++)
			cout << ' '<< getHex[memory[j] / 16] << getHex[memory[j] % 16];
			
		cout << '\n';
	}
	
	return 0;
}