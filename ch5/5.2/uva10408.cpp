#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <utility>

using namespace std;

#define MAX_N 1000

int N,K;

int getGCD(int a, int b)
{
	return b == 0 ? a : getGCD(b, a%b);
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	
	while (cin >> N >> K)
	{
		vector<pair<double, pair<int, int> > > v;
		v.push_back({ 1.0, {1,1} });
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (getGCD(i, j) == 1)
				{
					v.push_back({ 1.0 * j / i, {j,i} });
				}
			}
		}
		sort(v.begin(), v.end());

		cout << v[K - 1].second.first << '/' << v[K - 1].second.second << '\n';
	}

	return 0;

}