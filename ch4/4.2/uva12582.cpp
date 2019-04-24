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
#include <limits.h>
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;


const int INF = 987654321;

int tc, TC;
int N, M;

int degrees[128];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		memset(degrees, 0, sizeof degrees);
		
		string line;
		cin >> line;

		stack<char> s;
		s.push(line[0]);

		for (int i = 1; i < line.size(); i++)
		{
			if (s.top() == line[i])
			{
				s.pop();
				degrees[line[i]]++;
				
				if (!s.empty())
				{
					degrees[s.top()]++;
				}
				else
				{
					degrees[line[i]]--;
				}
			}
			else
			{
				s.push(line[i]);
			}
		}

		cout << "Case " << tc << '\n';
		for (char c = 'A'; c <= 'Z'; c++)
		{
			if (degrees[c])
			{
				cout << c << " = " << degrees[c] << '\n';
			}
		}
	}

	
	return 0;
}

