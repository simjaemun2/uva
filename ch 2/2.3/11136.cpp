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

using namespace std;

#define MAX_N 5000

int N,K;


int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (cin >> N && N > 0)
	{
		long long int result = 0;
		multiset<int> ms;
		multiset<int>::iterator mine, maxe;


		for (int n = 0; n < N; n++)
		{
			cin >> K;
			
			for (int k = 0; k < K; k++)
			{
				int a;
				cin >> a;
				ms.insert(a);
			}

			if (ms.size() > 1)
			{
				mine = ms.begin();
				maxe = ms.end();
				maxe--;
				result += *maxe - *mine;
				ms.erase(mine);
				ms.erase(maxe);
			}
		}

		cout << result << '\n';
	}
	
	
	return 0;
}