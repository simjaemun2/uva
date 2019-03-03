#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

#define MAX_N 250
#define INF 1000000

int N, P, Q;

int PP[MAX_N*MAX_N + 10];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int t;

		cin >> N >> P >> Q;

		P++, Q++;

		memset(PP, 0, sizeof(PP));

		for (int p = 1; p <= P; p++)
		{
			cin >> t;
			PP[t] = p;
		}
		
		/*
		PP[p]
		0 1 2 3 4 5 6 7 8 9
		0 1 0 6 4 3 0 2 5 7 
		
		v[]
		0 1 2 3 4 5 6 7
		1 4 6 3 5 7
		*/

		vector<int> v, result;

		for (int q = 1; q <= Q; q++)
		{
			cin >> t;

			if (PP[t])
				v.push_back(PP[t]);
		}

		for (int a : v)
		{
			auto it = lower_bound(result.begin(), result.end(), a);

			if (it == result.end())
			{
				result.push_back(a);
				//cout << a << '\n';
			}
			else
			{
				*it = a;
			}
		}
		
		cout << "Case " << tc << ": " << result.size() << '\n';
	}



	
	return 0;
}
