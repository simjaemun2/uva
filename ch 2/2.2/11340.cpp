#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define MAX_N 3000

int N;
int input[MAX_N];
bool isJolly;
bool diff[MAX_N];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		map<char, int> m;
		char c;
		int price, K;

		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> c >> price;
			m[c] = price;
		}

		cin >> K;
		cin.ignore();
		string line;

		price = 0;

		for (int j = 0; j < K; j++)
		{
			getline(cin, line);

			for (int l = 0; l < line.length(); l++)
			{
				auto it = m.find(line[l]);
				if (it != m.end())
				{
					price += it->second;
				}
			}
		}

		printf("%.2lf$\n", ((double)price) / 100);
	}
			

	

	return 0;
}