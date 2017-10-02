#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>

using namespace std;

#define MAX_N 1000

string source, target;

void dfs(int si, int ti, string result, stack<char> s)
{
	if (ti == source.length())
	{
		cout << result << '\n';
		return;
	}
	result += ' ';

	if (si < source.length())
	{
		s.push(source[si]);
		dfs(si + 1, ti, result + 'i', s);
		s.pop();
	}

	if (!s.empty() && s.top() == target[ti])
	{
		s.pop();
		dfs(si, ti + 1, result + 'o', s);
	}
}

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> source)
	{
		cin >> target;
		cout << "[\n";

		if (source.length() == target.length())
		{
			stack<char> s;
			s.push(source[0]);
			dfs(1, 0, "i", s);
		}
		cout << "]\n";
	}
	

	return 0;
}