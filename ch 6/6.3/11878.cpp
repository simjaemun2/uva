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
#include <sstream>

using namespace std;

#define O1 0
#define O2 1

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	string line;
	int sum = 0;

	while (cin >> line)
	{
		string o1, o2, right;
		char oper;
		
		int state = O1;

		for (int i = 0; i < line.length(); i++)
		{
			if (state == O1)
			{
				if (line[i] == '+' || line[i] == '-')
				{
					oper = line[i];
					state = O2;
				}
				else
				{
					o1 += line[i];
				}
			}
			else
			{
				if (line[i] == '=')
				{
					right = line.substr(i + 1);
					break;
				}
				else
				{
					o2 += line[i];
				}
			}
		}

		int result = oper == '+' ? stoi(o1) + stoi(o2) : stoi(o1) - stoi(o2);

		if (right != "?" && result == stoi(right) && 0 <= result && result <= 200)
			sum++;
	}
	
	cout << sum << '\n';

	return 0;
}
