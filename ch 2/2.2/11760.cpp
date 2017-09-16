#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

#define MAX_RC 10000
int R,C,N;
int r, c;

int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int tc = 0;

	while (cin >> R >> C >> N)
	{
		if (R + C + N == 0)
			return 0;
		bitset<MAX_RC> rSet;
		bitset<MAX_RC> cSet;

		for (int i = 0; i < N; i++)
		{
			cin >> r >> c;
			rSet.set(r);
			cSet.set(c);
		}
		/*
		Case 1: Escaped again! More 2D grid problems!
		Case 2: Party time! Let's find a restaurant!
		*/
		cin >> r >> c;
		bool result = true;

		for (int i = 0; i < 5; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 < nr && nr < R 
				&& 0 < nc && nc < C
				&& !rSet.test(nr) 
				&& !cSet.test(nc))
				result = false;
		}

		if (result)
			printf("Case %d: Party time! Let's find a restaurant!\n", ++tc);
		else
			printf("Case %d: Escaped again! More 2D grid problems!\n", ++tc);

		
	}
	

	return 0;
}