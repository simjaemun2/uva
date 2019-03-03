#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

string line;

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> line)
	{
		list<char> l;
		list<char>::iterator it = l.begin();
		
		for (int i = 0; i < line.size(); i++)
		{
			switch (line[i])
			{
			case '[':
				it = l.begin();
				break;
			case ']':
				it = l.end();
				break;
			default:
				l.insert(it,line[i]);
				break;
			}
			
		}

		for (it = l.begin(); it != l.end(); it++)
			cout << *it;
		cout << '\n';
	}
	

	return 0;
}