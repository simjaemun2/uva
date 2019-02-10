#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

#define MAX_N 100
#define MOD 1000000

int N, K;
typedef long long int LL;



int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;
	int a;

	while (cin >> a, a != -1)
	{
		if (tc > 1)
		{
			cout << '\n';
		}

		vector<int> v(1, 9999999);
		v.push_back(a);

		while (cin >> a, a != -1)
		{
			v.push_back(a);
		}

		vector<int> cache(v.size(), 0);

		for (int i = 1; i < v.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (v[i] <= v[j] && cache[i] < cache[j] + 1)
				{
					cache[i] = cache[j] + 1;
				}
			}
		}



		cout << "Test #" << tc++ << ":\n  maximum possible interceptions: "
			<< *max_element(cache.begin(), cache.end()) << "\n";

	}
	

	return 0;
}

