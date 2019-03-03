#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_TRACKS 20

int N, nTracks, RESULT, RESULT_index;
int input[MAX_TRACKS];

void rec(int tracks, int sum, int index)
{
	if (sum > N)
		return;
	if (sum > RESULT)
	{
		RESULT = sum;
		RESULT_index = index;
	}
	
	if (tracks == nTracks)
		return;

	rec(tracks + 1, sum + input[tracks], index | (1 << tracks));
	rec(tracks + 1, sum, index);
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		cin >> nTracks;

		for (int i = 0; i < nTracks; i++)
			cin >> input[i];

		RESULT = 0;

		rec(0, 0, 0);

		for (int i = 0; i < nTracks; i++)
		{
			if (RESULT_index & (1 << i))
				cout << input[i] << ' ';
		}

		cout << "sum:" << RESULT << '\n';
	}

	return 0;
}

