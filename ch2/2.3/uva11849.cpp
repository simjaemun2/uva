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

#define MAX_N 5000

int N,M;


int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while ((cin >> N >> M) && (N + M > 0))
	{
		set<int> s;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			s.insert(a);
		}

		int result = 0;

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			
			if (s.find(a) != s.end())
				result++;
		}
		cout << result << '\n';
	}



	
	return 0;
}