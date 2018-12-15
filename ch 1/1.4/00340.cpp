#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_N 1000
#define CNT 10

int N;

int S[MAX_N + 1];
int G[MAX_N + 1];
int TCS[CNT];
int CS[CNT];
int CG[CNT];


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	bool allZero;

	int TC = 1;

	while (cin >> N, N)
	{
		cout << "Game " << TC++ << ":\n";

		for (int c = 1; c < CNT; c++)
		{
			CS[c] = 0;
		}

		for (int n = 0; n < N; n++)
		{
			cin >> S[n];
			CS[S[n]]++;
		}

		while (true)
		{
			int strong = 0;
			int match = 0;

			for (int c = 1; c < CNT; c++)
			{
				CG[c] = 0;
			}

			for (int n = 0; n < N; n++)
			{
				cin >> G[n];
				CG[G[n]]++;
			}

			if (!G[0])
				break;

			for (int c = 1; c < CNT; c++)
			{
				TCS[c] = CS[c];
			}

			for (int n = 0; n < N; n++)
			{
				if (G[n] == S[n])
				{
					strong++;
					CG[G[n]]--;
					TCS[S[n]]--;
				}
			}

			for (int c = 1; c < CNT; c++)
			{
				if (CG[c] && TCS[c])
				{
					match += min(CG[c] , TCS[c]);
				}
			}

			cout << "    (" << strong << ',' << match << ")\n";
		}
	}
	

	return 0;
}

