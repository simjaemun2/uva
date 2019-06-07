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
int DY[] = { -1,-2,-2,-1,1,2,2,1 };
int DX[] = {  -2,-1,1,2,-2,-1,1,2};

int KY[] = { -1,-1,-1,0,0,1,1,1 };
int KX[] = { -1,0,1,-1,1,-1,0,1 };
const int MAX_D = 8;

const int MAX_N = 100;
int N, M;

char board[MAX_N][MAX_N + 1];

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> M;
		vector<PII> horses;
		PII src, dst;


		for (int n = 0; n < N; n++)
		{
			cin >> board[n];
			for (int m = 0; m < M; m++)
			{
				if (board[n][m] == 'Z')
				{
					horses.push_back({ n,m });
				}
				else if (board[n][m] == 'A')
				{
					src.first = n;
					src.second = m;
				}
				else if (board[n][m] == 'B')
				{
					dst.first = n;
					dst.second = m;
				}
			}
		}

		for (auto h : horses)
		{
			for (int d = 0; d < MAX_D; d++)
			{
				int ny = h.first + DY[d];
				int nx = h.second + DX[d];

				if (0 <= ny && ny < N && 0 <= nx && nx < M && board[ny][nx] == '.')
				{
					board[ny][nx] = 'Z';
				}
			}
		}

		queue<pair<int, PII> > q({ {0, src} });
		set<PII> s({ src });
		int answer = -1;
		while (!q.empty())
		{
			PII cur = q.front().second;
			int step = q.front().first;
			q.pop();
			if (cur == dst)
			{
				answer = step;
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int ny = cur.first + KY[d];
				int nx = cur.second + KX[d];
				
				PII next = { ny, nx };
				if (0 <= ny && ny < N && 0 <= nx && nx < M 
					&& (board[ny][nx] == '.' || board[ny][nx] == 'B')
					&& s.find(next) == s.end())
				{
					s.insert(next);
					q.push({ step + 1, next });
				}
			}
		}

		if (answer == -1)
		{
			cout << "King Peter, you can't go now!\n";
		}
		else
		{
			cout << "Minimal possible length of a trip is " << answer << '\n';
		}
	}



	return 0;
}