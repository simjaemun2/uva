#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX_K 7777
#define MAX_GRID 6
#define MAX_PASS 5

vector<char> first[MAX_PASS];
vector<char> second[MAX_PASS];
int k,K;
vector<char> common[MAX_PASS];
string answer;
/*
AYGSU CBOPT
DOMRA DOSBG
CPFAS GTRAR
XBODG APMMS
WDYPK WSXNU
PRXWO EFGHI
*/

void rec(int n)
{
	if (n == MAX_PASS)
	{
		k++;
		if (k == K)
		{
			cout << answer << '\n';
		}

		return;
	}

	for (int i = 0; i < common[n].size(); i++)
	{
		if (k < K)
		{
			answer[n] = common[n][i];
			rec(n + 1);
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;


	for (int tc = 0; tc < T; tc++)
	{
		cin >> K;
		
		for (int i = 0; i < MAX_PASS; i++)
		{
			first[i].clear();
			second[i].clear();
		}

		for (int i = 0; i < MAX_GRID; i++)
		{
			for (int j = 0; j < MAX_PASS; j++)
			{
				char c;
				cin >> c;
				first[j].push_back(c);
			}
		}
			
		for (int i = 0; i < MAX_GRID; i++)
		{
			for (int j = 0; j < MAX_PASS; j++)
			{
				char c;
				cin >> c;
				second[j].push_back(c);
			}
		}
		
		for (int i = 0; i < MAX_PASS; i++)
		{
			common[i].clear();

			sort(first[i].begin(), first[i].end());
			sort(second[i].begin(), second[i].end());

			for (auto c : first[i])
			{
				if (binary_search(second[i].begin(), second[i].end(), c) &&
					!binary_search(common[i].begin(), common[i].end(), c)
					)
				{
					common[i].push_back(c);
				}
					
			}
		}

		int maxPass = 1;

		for (int i = MAX_PASS - 1; i >=0; i--)
		{
			maxPass *= common[i].size();
		}
		
		if (maxPass < K || maxPass == 0)
		{
			cout << "NO\n";
			continue;
		}
		answer = "12345";
		k = 0;
		rec(0);

	}
	

	return 0;
}

