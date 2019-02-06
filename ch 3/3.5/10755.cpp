#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
typedef long long int LL;

int tc, TC;

const int MAX_ABC = 20;
int A, B, C;

LL cache[MAX_ABC+1][MAX_ABC+1][MAX_ABC + 1];


int main(int argc, char** argv)
{
	/*
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> A >> B >> C;

		LL answer = -9999999999999;

		for (int a = 1; a <= A; a++)
		{
			for (int b = 1; b <= B; b++)
			{
				for (int c = 1; c <= C; c++)
				{
					cin >> cache[a][b][c];
					answer = max(answer, cache[a][b][c]);
					cache[a][b][c] += cache[a][b - 1][c] + cache[a][b][c - 1] - cache[a][b - 1][c - 1];
				}
			}
		}

		if (answer >= 0)
		{
			for (int sb = 1; sb <= B; sb++)
			{
				for (int sc = 1; sc <= C; sc++)
				{
					for (int eb = sb; eb <= B; eb++)
					{
						for (int ec = sc; ec <= C; ec++)
						{
							LL sum = 0;

							for (int a = 1; a <= A; a++)
							{
								sum = max(0LL, sum + cache[a][eb][ec]
									- cache[a][sb - 1][ec] - cache[a][eb][sc - 1] + cache[a][sb - 1][sc - 1]);
								answer = max(answer, sum);
							}
						}
					}
				}
			}
		}

		cout << answer << '\n';
		if (tc < TC)
			cout << '\n';
	}


	return 0;
}