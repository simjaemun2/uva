#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

const int MAX_N = 100;

int cache[MAX_N + 2][MAX_N + 2];

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

	

	int N;

	while (cin >> N)
	{

		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				cin >> cache[y][x];
				cache[y][x] += cache[y][x - 1] + cache[y - 1][x] - cache[y - 1][x - 1];
			}
		}

		int ret = -127 * 101 * 101;

		for (int sy = 1; sy <= N; sy++)
		{
			for (int sx = 1; sx <= N; sx++)
			{
				for (int ey = sy; ey <= N; ey++)
				{
					for (int ex = sx; ex <= N; ex++)
					{
						ret = max(ret, cache[ey][ex] - cache[ey][sx - 1] - cache[sy - 1][ex] + cache[sy - 1][sx - 1]);
					}
				}
			}
		}

		cout << ret << '\n';
	}


	return 0;
}