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

string A, B;
int na[127];
int nb[127];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (getline(cin, A))
	{
		getline(cin, B);
		memset(na, 0, sizeof(na));
		memset(nb, 0, sizeof(nb));

		for (auto c : A)
			na[c]++;
		for (auto c : B)
			nb[c]++;
		for (int c = 'a'; c <= 'z'; c++)
		{
			int a = min(na[c], nb[c]);
			if (a > 0)
			{
				while (a--)
				{
					cout << char(c);
				}
			}
		}
		cout << '\n';
	}


	return 0;
}
