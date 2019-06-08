#define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <iostream>

#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>
#include <map>
#include <limits.h>
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 8;

const int MAX_N = 100;
int N, M;

int board[MAX_N][MAX_N];

const int MAX_MOVE = 3;
int moveY[2][MAX_MOVE] =
{
	{0,0,1},
	{0,0,-1}
};

int moveX[MAX_MOVE] = { -1,1,0 };

const int MAX_JUMP = 5;
int jumpY[2][MAX_JUMP] = {
	{0, 1, 1, 1,0},
	{0,-1,-1,-1,0}
};
int jumpX[MAX_JUMP] = { -1,-1,0,1,1 };


bool compare(const pair<int, PII>& a, const pair<int, PII>& b)
{
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	tc = 1;

	while (cin >> N >> M)
	{
		if (tc != 1)
			cout << '\n';
		tc++;

		memset(board, -1, sizeof board);

		for (int i = 0; i < 2 * M; i++)
		{
			int y, x;
			cin >> y >> x;
			board[y][x] = 0;
		}

		for (int i = 0; i < 2 * M; i++)
		{
			int y, x;
			cin >> y >> x;
			board[y][x] = 1;
		}

		int sy, sx, color;
		cin >> sy >> sx;
		color = 0;
		
		board[sy][sx] = -3;

		vector<pair<int, PII> > v;
		set<PII> s;

		for(int m = 0; m < MAX_MOVE; m++)
		{
			int ny = sy + moveY[color][m];
			int nx = sx + moveX[m];

			if (1 <= ny && ny <= N && 1 <= nx && nx < M
				&& board[ny][nx] == -1)
			{
				v.push_back({ -1, {ny, nx} });
				s.insert({ ny, nx });
			}
		}


		priority_queue<pair<int, PII> > pq;
		pq.push({ 0, {sy, sx} });

		while (!pq.empty())
		{
			int step = pq.top().first;
			int cy = pq.top().second.first;
			int cx = pq.top().second.second;

			pq.pop();

			for (int j = 0; j < MAX_JUMP; j++)
			{
				int py = cy + jumpY[color][j];
				int px = cx + jumpX[j];

				if (1 <= py && py <= N && 1 <= px && px < M
					&& board[py][px] >= 0)
				{
					int ny = py + jumpY[color][j];
					int nx = px + jumpX[j];

					if (1 <= ny && ny <= N && 1 <= nx && nx < M
						&& board[ny][nx] == -1 && s.find({ ny, nx }) == s.end())
					{
						v.push_back({ step - 1, {ny, nx} });
						pq.push({ step - 1, {ny, nx} });
						s.insert({ ny, nx });
					}
				}
			}
		}

		sort(v.begin(), v.end(), compare);

		for (auto p : v)
		{
			cout << p.second.first << ' ' << p.second.second << ' ' << -p.first << '\n';
		}
	}


	return 0;
}