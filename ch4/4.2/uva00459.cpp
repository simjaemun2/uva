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
const int MAX_N = 26;
int tc, TC;
int N;

int last;
int parents[MAX_N];
int ranks[MAX_N];
int answer;


int findParent(int c)
{
	if (c != parents[c])
		return parents[c] = findParent(parents[c]);
	return c;
}

void connect(int a, int b)
{
	int pa = findParent(a);
	int pb = findParent(b);

	if (pa != pb)
	{
		answer--;
		if (ranks[pa] > ranks[pb])
		{
			parents[pb] = pa;
		}
		else
		{
			parents[pa] = pb;
			if (ranks[pa] == ranks[pb])
			{
				ranks[pb]++;
			}
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	string line;
	getline(cin, line);
	
	TC = stoi(line);
	getline(cin, line);
	for (tc = 1; tc <= TC; tc++)
	{
		getline(cin, line);
		last = line[0] - 'A';
		answer = last+1;
		for (int i = 0; i <= last; i++)
		{
			parents[i] = i;
			ranks[i] = 0;
		}

		while (getline(cin, line) && line.size() > 0)
		{
			connect(line[0] - 'A', line[1] - 'A');
		}

		cout << answer << '\n';

		if (tc < TC)
			cout << '\n';
	}

	return 0;
}

