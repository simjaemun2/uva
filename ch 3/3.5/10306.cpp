#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAX_M 40
#define MAX_S 300
#define INF 999999999

int N, M, S;

typedef long long int LL;

int cache[MAX_S + 1][MAX_S + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M >> S;

		vector<pair<int, int> > v;
		vector<int> pow2;

		for (int m = 0; m < M; m++)
		{
			LL a, b;
			cin >> a >> b;
			LL sum = a*a + b*b;
			if (sum > S*S)
				continue;

			v.push_back(make_pair(a, b));
			pow2.push_back(sum);
		}

		for (int i=0; i<=S; i++)
		{
			for (int j = 0; j <= S; j++)
			{
				cache[i][j] = INF;
			}
		}

		cache[0][0] = 0;

		for (int m = 0; m < v.size(); m++)
		{
			int X = v[m].first;
			int Y = v[m].second;
			for (int x = X; x*x + Y*Y <= S*S; x++)
			{
				for (int y = Y; x*x + y*y <= S*S; y++)
				{
					cache[x][y] = min(cache[x][y], cache[x - X][y - Y] + 1);
				}
			}
		}

		int ans = INF;

		for (int x = 0; x <= S; x++)
		{
			for (int y = 0; y <= S; y++)
			{
				if(x*x + y*y == S*S)
					ans = min(ans, cache[x][y]);
			}
		}

		if (ans == INF)
			cout << "not possible\n";
		else
			cout << ans << '\n';
	}


	return 0;
}

