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

using namespace std;


#define INF 987654321

#define MAX_RC 4
#define MAX_D 8

typedef long long int LL;

int R, C, N;

int DR[MAX_D] = { -1,-1,-1,0,0,1,1,1 };
int DC[MAX_D] = { -1,0,1,-1,1,-1,0,1 };

LL cache[1 << (MAX_RC * MAX_RC + MAX_RC)];

LL dp(int state)
{
	LL& ret = cache[state];

	if (ret != -1LL)
		return ret;

	int step = state >> (MAX_RC*MAX_RC);
	int board = state & ((1 << (MAX_RC*MAX_RC)) - 1);

	/*
	if (step == N - 1)
	{
		int cnt = 0;

		for (int n = 0; n < MAX_RC*MAX_RC; n++)
		{
			if (board & (1 << n))
				cnt++;
		}

		return ret = (cnt == 1 ? 1LL : 0LL);
	}
	*/
	
	ret = 0LL;

	int cnt = 0;

	for (int n = 0; n < MAX_RC*MAX_RC; n++)
	{
		if (board & (1 << n))
			cnt++;
	}

	if (cnt > N - step)
		return ret;

	if (step == N - 1)
	{
		return ret = cnt == 1 ? 1LL : 0LL;
	}

	for (int i = 0; i < R*C; i++)
	{
		if (board & (1 << i))
		{
			int cr = i / C;
			int cc = i % C;

			for (int d = 0; d < MAX_D; d++)
			{
				int jr1 = cr + DR[d];
				int jc1 = cc + DC[d];

				if (0 <= jr1 && jr1 < R && 0 <= jc1 && jc1 < C)
				{
					int nextBoard = board & ~(1 << i);
					int nextStep = (step + 1) << (MAX_RC*MAX_RC);
					
					if (board & (1 << (jr1 * C + jc1)))
					{
						int jr2 = jr1 + DR[d];
						int jc2 = jc1 + DC[d];

						if (0 <= jr2 && jr2 < R && 0 <= jc2 && jc2 < C && !(board & (1 << (jr2 * C + jc2))))
						{
							ret += dp(nextStep | (nextBoard & ~(1 << (jr1 * C + jc1))) | (1 << (jr2 * C + jc2)));
						}
					}
					/*
					else
					{
						ret += dp(nextStep | (nextBoard | (1 << (jr1 * C + jc1))));
					}
					*/
				}
			}
		}
	}

	return ret;
}


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		memset(cache, -1LL, sizeof cache);

		cin >> R >> C >> N;

		int state = 0;

		for (int n = 0; n < N; n++)
		{
			int x, y;
			cin >> x >> y;
			state |= 1 << ((y - 1) + (x - 1)*C);
		}

		cout << "Case " << tc << ": " << dp(state) << '\n';
	}

	return 0;
}
