#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <stack>

using namespace std;

int K;

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (scanf("%d",&K) != -1)
	{
		stack<pair<int, int> > s;

		for (int x = 2 * K; x > K; x--)
		{
			double y =  ((double)K*x) / (x - K);
			if (y - int(y) < 0.0000001)
			{
				s.push(make_pair((int)y, x));
			}
		}

		printf("%d\n", s.size());
		while (!s.empty())
		{
			printf("1/%d = 1/%d + 1/%d\n", K, s.top().first, s.top().second);
			s.pop();
		}
	}
	

	return 0;
}