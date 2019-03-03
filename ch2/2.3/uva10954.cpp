#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

int N;

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N && N > 0)
	{
		priority_queue<int> pq;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			pq.push(-a);
		}

		while (pq.size() > 1)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			sum += a + b;
			pq.push(a + b);
		}

		cout << -sum << '\n';
	}
	return 0;
}