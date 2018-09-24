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

struct Expr{
	char oper;
	string exp;
};

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
		string line, clause, col;
		cin >> line;
		istringstream iss_clause(line);

		bool isPossible;

		while (getline(iss_clause, clause, '|'))
		{
			istringstream iss_col(clause.substr(1, clause.length()-2)); // iss _ conjunction of literals

			set<string> s;

			isPossible = true;

			while (getline(iss_col, col, '&'))
			{
				if (col.length() == 1)
				{
					if (s.find("~"+col) != s.end())
					{
						isPossible = false;
						break;
					}
				}
				else
				{
					if (s.find(string(1,col[1])) != s.end())
					{
						isPossible = false;
						break;
					}
				}
				s.insert(col);
			}

			if (isPossible)
			{
				cout << "YES\n";
				break;
			}
		}

		if (!isPossible)
			cout << "NO\n";
	}
	

	return 0;
}
