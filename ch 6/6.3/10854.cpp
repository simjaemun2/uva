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

string line;
typedef long long int LL;
int idx;

LL rec(vector<string>& v)
{
	LL ret=0, mid;

	if (v[idx] == "IF")
	{
		idx++;
		mid = 1;
		while (true)
		{
			if (v[idx] == "IF")
			{
				mid *= rec(v);
			}
			else
			{
				break;
			}
		}
		ret += mid;
	}
	
	if (v[idx] == "ELSE")
	{
		idx++;
		mid = 1;
		while (true)
		{
			if (v[idx] == "IF")
			{
				mid *= rec(v);
			}
			else
			{
				break;
			}
		}
		ret += mid;
	}

	idx++;

	return ret;
}

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
		vector<string> v;

		while (cin >> line)
		{
			if (line == "ENDPROGRAM")
				break;
			else if(line != "S")
				v.push_back(line);
		}

		idx = 0;
		
		LL result = 1;
		
		while (idx < v.size())
			result *= rec(v);

		cout << result << '\n';
	}

	return 0;
}
