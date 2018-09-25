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
#include <locale>

using namespace std;

int N;

bool compare(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second != b.second)
		return a.second < b.second;

	for (int i = 0; i < a.first.length() && i < b.first.length(); i++)
	{
		if (tolower(a.first[i]) != tolower(b.first[i]))
		{
			return tolower(a.first[i]) < tolower(b.first[i]);
		}
	}

	return a.first.length() < b.first.length();
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N)
	{
		vector<pair<string, int> > v;

		while (N--)
		{
			string name,temp;
			int m, s, ms;
			cin >> name >> temp >> m >> temp >> s >> temp >> ms >> temp;
			v.push_back({ name, m * 60 * 1000 + s * 1000 + ms });
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i += 2)
		{
			cout << "Row " << i / 2 + 1 << '\n';
			cout << v[i].first << '\n';
			if(i+1 < v.size())
				cout << v[i+1].first << '\n';
		}

		cout << '\n';
	}
	

	return 0;
}
