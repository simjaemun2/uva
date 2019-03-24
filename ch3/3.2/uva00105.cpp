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
const int MAX_N = 100000;

int tc, TC;
int heights[10010];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int L, H, R;
	int rmax = 0;

	while (cin >> L >> H >> R)
	{
		for (int i = L; i < R; i++)
		{
			heights[i] = max(heights[i], H);
		}
		rmax = max(rmax, R);
	}

	vector<int> answer;

	for (int left = 1, h = 0; left <= rmax; left++)
	{
		if (h != heights[left])
		{
			answer.push_back(left);
			answer.push_back(heights[left]);
			h = heights[left];
		}
	}

	cout << answer[0];
	for (int i = 1; i < answer.size(); i++)
		cout << ' ' << answer[i];
	cout << '\n';

	
	return 0;
}