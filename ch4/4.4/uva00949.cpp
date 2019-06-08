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

const int MAX_D = 4;
int DY[] = { -1,1,0,0 };
int DX[] = { 0,0,-1,1 };

const int MAX_VH = 100;
const int MAX_R = 500;

int Y, X, R, M;



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	while (cin >> X >> Y >> R)
	{
		vector<vector<PII> > adj(Y*X);

		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				for (int d = 0; d < MAX_D; d++)
				{
					int ny = DY[d] + y;
					int nx = DX[d] + x;

					if (0 <= ny && ny < Y && 0 <= nx && nx < X)
					{
						adj[X*y + x].push_back({ ny, nx });
					}
				}
			}
		}

		for (int r = 0; r < R; r++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			PII p2 = { y2 , x2 };
			auto it1 = find(adj[X*y1 + x1].begin(), adj[X*y1 + x1].end(), p2);
			if (it1 != adj[X*y1 + x1].end())
				adj[X*y1 + x1].erase(it1);
		}

		cin >> M;

		set<pair<int, PII> > monitoredSet;

		for (int m = 0; m < M; m++)
		{
			int t, x, y;
			cin >> t >> x >> y;
			monitoredSet.insert({ t, {y,x} });
		}

		queue<pair<int, PII> > q;
		q.push({ 0, {0,0} });
		int answer = -1;
		set<PII> s({ {0,0} });

		while (!q.empty() && answer == -1)
		{
			int step = q.front().first;
			int cy = q.front().second.first;
			int cx = q.front().second.second;
			q.pop();

			if (cy == Y - 1 && cx == X - 1)
			{
				answer = step;
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				int ny = cy + DY[d];
				int nx = cx + DX[d];
				PII np = { ny, nx };
				auto it = find(adj[X*cy + cx].begin(), adj[X*cy + cx].end(), np);

				if (it != adj[X*cy + cx].end() && s.find(np) == s.end())
				{
					if (monitoredSet.find({ step + 1, np }) == monitoredSet.end())
					{
						s.insert(np);
						q.push({ step + 1, np });
					}
					else
					{
						q.push({ step + 1, {cy, cx} });
					}
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}