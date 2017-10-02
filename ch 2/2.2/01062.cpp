#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>

using namespace std;

#define MAX_N 1000

string input;



int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 0;
	while (cin >> input)
	{
		tc++;
		if (!input.compare("end"))
			return 0;

		stack<int> s[26];
		int s_index = -1;
		for (int i = 0; i < input.length(); i++)
		{
			int c = input[i] - 'A';
			int min_diff = 30;
			int min_index = -1;
			
			for (int j = 0; j <= s_index; j++)
			{
				if (!s[j].empty() && s[j].top() - c >= 0 && s[j].top() - c < min_diff)
				{
					min_index = j;
					min_diff = s[j].top() - c;
				}
			}

			if (min_diff == 30)
				s[++s_index].push(c);
			else
				s[min_index].push(c);
		}

		printf("Case %d: %d\n", tc, s_index+1);
	}
	
	return 0;
}