#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>
#include <math.h>
#include <functional>

using namespace std;

#define INF 987654321
#define MAX_TH 2000
#define MAX_F 500

int T, H, F;

int acorn[MAX_TH + 1][MAX_TH + 1];
int cache[MAX_TH + 1];

int main(int argc, char** argv)
{
	int TC;
	cin >> TC;

	while (TC--)
	{
		memset(acorn, 0, sizeof acorn);
		memset(cache, 0, sizeof cache);

		cin >> T >> H >> F;

		for (int t = 0; t < T; t++)
		{
			int N;
			cin >> N;

			while(N--)
			{
				int h;
				cin >> h;
				acorn[t][h]++;
			}
		}

		for (int t = 0; t < T; t++)
		{
			cache[H] = max(cache[H], acorn[t][H]);
		}

		for (int h = H - 1; h >= 0; h--)
		{
			for (int t = 0; t < T; t++)
			{
				acorn[t][h] += max(acorn[t][h + 1], ((h + F <= H) ? cache[h + F] : 0));

				cache[h] = max(cache[h], acorn[t][h]);
			}
		}

		cout << cache[0] << '\n';
	}
	
	return 0;
}