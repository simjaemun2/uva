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
#include <math.h>

using namespace std;

string line;

vector<int> kmpPreprocess(string s)
{
	int i = 0, j = -1;
	
	vector<int> b(s.size() + 1, 0);
	
	b[0] = -1;

	while (i < s.size())
	{
		while (j >= 0 && s[i] != s[j])
			j = b[j];

		i++, j++;

		b[i] = j;
	}

	return b;
}

vector<int> kmpSearch(string t, string p)
{
	int i = 0, j = 0;
	vector<int> b = kmpPreprocess(p);

	vector<int> ret;

	while (i < t.size())
	{
		while (j >= 0 && t[i] != p[j])
			j = b[j];
		
		i++, j++;
		

		if (j == p.size())
		{
			ret.push_back(i - j);
			j = b[j];
		}
	}

	return ret;
}

int kmpLine(string t, string p)
{
	int i = 0, j = 0;
	vector<int> b = kmpPreprocess(p);

	while (i < t.size())
	{
		while (j >= 0 && t[i] != p[j])
			j = b[j];

		i++, j++;
	}

	return j;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> line)
	{
		string reversed = string(line.rbegin(), line.rend());
			
		int index = kmpLine(line, reversed);

		cout << line << reversed.substr(index) << '\n';

	}
	

	return 0;
}
