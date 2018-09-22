#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>



using namespace std;

#define MAX_N 250
#define MOD 27

int numc[MAX_N + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	string line;
	set<string> s;

	while (getline(cin, line), line[0] != '#')
		s.insert(line);

	getline(cin, line);
	
	for (int i=0; i<line.size(); i++)
	{
		if (line[i] == ' ')
			numc[i] = 0;
		else
			numc[i] =  line[i]+ 1 - 'A';
	}

	for (int i = 26; i >= 0; i--)
	{
		string w = "";
		int j;
		bool isPossible = false;
		for (j = 0; j < line.size(); j++)
		{
			int d = (numc[j] + i) % MOD;
			if (d)
			{
				w += (char)('A' + d - 1);
			}
			else
			{
				if (s.find(w) != s.end())
				{
					isPossible = true;
				}
				w = "";
			}
		}

		if (isPossible)
		{
			string w = "";

			int l = 0;

			for (j = 0; j < line.size(); j++)
			{
				char c;
				int d = (numc[j] + i) % MOD;
				if (d)
				{
					w += (char)('A' + d - 1);
				}
				else
				{
					if (l + w.length() > 60)
					{
						cout << '\n';
						cout << w.substr(1);
						l = w.length();
					}
					else
					{
						cout << w;
						l += w.length();
					}
					w = " ";
				}
			}
			if (w.length() > 1)
				cout << w;
			cout << '\n';

			return 0;
		}
	}

	return 0;
}
