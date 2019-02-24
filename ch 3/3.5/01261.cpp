#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>

using namespace std;

typedef long long int LL;
typedef pair<int, int > II;

const int INF = 987654321;
const int MAX_LEN = 25;

int tc, TC;

string input;
set<string> s;

int dp(string str)
{
	if (str == "")
	{
		return 1;
	}

	if (s.find(str) != s.end())
	{
		return 0;
	}

	s.insert(str);

	int i = 1;
	int si = 0;

	int ret = 0;

	for (; i <= str.length(); i++)
	{
		if (si == 0 && i == str.length() && i - si >= 2)
		{
			return 1;
		}
		else if (str[si] != str[i])
		{
			if (i - si >= 2)
			{
				string cs = str;
				cs.erase(si, i - si);
				ret |= dp(cs);

				if (ret)
					return ret;
			}
			si = i;
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> input;
		s.clear();
		int answer = dp(input);
		cout << answer << '\n';
	}
	
	
	
	return 0;
}

