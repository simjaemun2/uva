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
#include <map>

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_N = 1000;



int tc, TC;
int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		
		string cur;
		cin >> cur;

		vector<string> s;

		for (int n = 1; n < N; n++)
		{
			string next;
			cin >> next;
			s.push_back(next);
		}

		int sum = cur.length();
		vector<string> v(1, cur);

		for (int n = 1; n < N; n++)
		{
			int cnt = 0;
			auto next_it = s.begin();
			
			int cur_len = cur.length();

			for (auto it = s.begin(); it != s.end(); it++)
			{
				int i = 0;

				string next = *it;
				int next_len = next.length();
				
				for (; i < cur_len && i < next_len && cur[i] == next[i]; i++);

				if (cnt < i)
				{
					cnt = i;
					next_it = it;
				}
			}

			sum += (*next_it).length() - cnt;
			cur = *next_it;
			s.erase(next_it);
			v.push_back(cur);
		}

		cout << sum << '\n';
		for (string s : v)
		{
			cout << s << '\n';
		}
	}
		
	return 0;

}