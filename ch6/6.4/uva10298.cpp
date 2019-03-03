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
	
	vector<int> v(s.size() + 1, 0);
	
	v[0] = -1;

	while (i < s.size())
	{
		while (j >= 0 && s[i] != s[j])
			j = v[j];

		i++, j++;

		v[i] = j;
	}

	return v;
}

vector<int> kmpSearch(string t, string p)
{
	int i = 0, j = 0;
	
	vector<int> v = kmpPreprocess(p);
	vector<int> result;
	
	while (i < t.size())
	{
		while (j >= 0 && t[i] != p[j])
			j = v[j];
		i++, j++;
		
		if (j == p.size())
		{
			result.push_back(i - j);
			j = v[j];
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> line, line != ".")
	{
		string line2 = line + line;
		cout << kmpSearch(line2, line).size() - 1<< '\n';
	}
	

	return 0;
}
