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

const int MAX_N = 300;
const int MAX_RANGE = 1001;

int N;

LL cache[MAX_N + 1][MAX_N + 1];

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cache[0][0] = 1;

	for (int i = 1; i <= MAX_N; i++)
	{
		for (int j = i; j <= MAX_N; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				cache[j][k] += cache[j - i][k - 1];
			}
		}
	}


	string line;
	while (getline(cin, line))
	{
		vector<int> inputs;
		int a;
		istringstream iss(line);
		while (iss >> a)
		{
			inputs.push_back(a);
		}
		int l1, l2;

		N = inputs[0];

		if (inputs.size() == 1)
		{
			l1 = 0, l2 = N;
		}
		else if (inputs.size() == 2)
		{
			l1 = 0, l2 = inputs[1];
		}
		else
		{
			l1 = inputs[1], l2 = inputs[2];
		}

		if (l2 > N)
			l2 = N;

		LL answer = 0;

		for (int i = l1; i <= l2; i++)
		{
			answer += cache[N][i];
		}

		cout << answer << '\n';
	}
	
	return 0;
}

