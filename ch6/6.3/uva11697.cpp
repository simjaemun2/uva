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

#define MAX_N 1000
#define TABLE_RC 5

string key, toEnc;
int tableR[127];
int tableC[127];
char table[TABLE_RC][TABLE_RC];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	cin.ignore(100, '\n');
	while (T--)
	{
		getline(cin, key);
		getline(cin, toEnc);

		memset(tableR, 0, sizeof(tableR));
		memset(tableC, 0, sizeof(tableC));
		memset(table, 0, sizeof(table));

		set<char> s;

		for (int i = 0; i < key.length(); i++)
		{
			char k = key[i] - 32;
			
			if (key[i] != ' ' && s.find(k) == s.end())
			{
				tableR[k] = s.size() / TABLE_RC;
				tableC[k] = s.size() % TABLE_RC;
				table[s.size() / TABLE_RC][s.size() % TABLE_RC] = k;
				s.insert(k);
			}
		}

		for (int k = 'A'; k <= 'Z'; k++)
		{
			if (k != 'Q' && s.find(k) == s.end())
			{
				tableR[k] = s.size() / TABLE_RC;
				tableC[k] = s.size() % TABLE_RC;
				table[s.size() / TABLE_RC][s.size() % TABLE_RC] = k;
				s.insert(k);
			}
		}

		string enc = "";

		stack<char> st;

		for (int i = toEnc.size() - 1; i >= 0; i--)
		{
			if (toEnc[i] != ' ')
			{
				st.push(toEnc[i] - 32);
			}
		}

		//HI DE TH EG OL DI NT HE TR EE ST UM P
		//BM ND ZB XD KY BE JV DM UI XM MN UV IF
		//YDVHCWSPKNTAHKUBIPERMHGHDVRU

		while (!st.empty())
		{
			char a, b;
			
			a = st.top();
			st.pop();
			
			if (st.empty())
			{
				b = 'X';
			}
			else
			{
				b = st.top();
				st.pop();
			}
			
			if (a == b)
			{
				st.push(b);
				b = 'X';
			}

			if (tableR[a] == tableR[b])
			{
				enc += table[tableR[a]][(tableC[a] + 1) % TABLE_RC];
				enc += table[tableR[b]][(tableC[b] + 1) % TABLE_RC];
			}
			else if (tableC[a] == tableC[b])
			{
				enc += table[(tableR[a] + 1) % TABLE_RC][tableC[a]];
				enc += table[(tableR[b] + 1) % TABLE_RC][tableC[b]];
			}
			else
			{
				enc += table[tableR[a]][tableC[b]];
				enc += table[tableR[b]][tableC[a]];
			}
			
		}

		cout << enc << '\n';
	}

	return 0;
}
