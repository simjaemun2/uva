#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

string line;

#define BEFORE_M 0
#define BETWEEN 1
#define AFTER_E 2
#define IMPOSSIBLE 3

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	while (T--)
	{
		cin >> line;
		
		int state = BEFORE_M;
		int index = -1;
		

		for (int i = 0; i < line.size(); i++)
		{
			if (state == BEFORE_M)
			{
				if (line[i] != '?')
				{
					if (i && line[i] == 'M')
					{
						state = BETWEEN;
						index = i;
					}
					else
					{
						state = IMPOSSIBLE;
						break;
					}
				}
			}
			else if (state == BETWEEN)
			{
				if (line[i] != '?')
				{
					if (line[i] == 'E' && i - 1 != index)
					{
						index = i;
						state = AFTER_E;
					}
					else
					{
						state = IMPOSSIBLE;
						break;
					}
				}
			}
			else
			{
				if (line[i] != '?')
				{
					state = IMPOSSIBLE;
					break;
				}
			}
		}

		if (state == AFTER_E && index - 1 == line.size() - index - 1)
			cout << "theorem\n";
		else
			cout << "no-theorem\n";
	}


	return 0;
}
