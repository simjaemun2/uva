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

using namespace std;

int N;
string line;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N >> line)
	{
		map<string, int> m;
		
		int mostFreqSize = -1;
		string mostFeqStr;

		for (int i = 0; i <= line.size() - N; i++)
		{
			string sub = line.substr(i, N);

			if (m.find(sub) == m.end())
				m[sub] = 1;
			else
				m[sub] += 1;

			if (m[sub] > mostFreqSize)
			{
				mostFreqSize = m[sub];
				mostFeqStr = sub;
			}
		}

		cout << mostFeqStr << '\n';
	}


	return 0;
}
