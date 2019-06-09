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
const int MAX_DIAG = 8;
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};

int N, S;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N >> S;

		VI cnt(N + 1);
		VVI adj(N + 1);
		set<int> imps;

		for (int s = 1; s <= S; s++)
		{
			int prev, cur;
			cin >> prev;
			
			while(cin >> cur, cur)
			{
				adj[cur].push_back(prev);
				adj[prev].push_back(cur);

				if (cnt[prev] > 0 && cnt[prev] != s)
				{
					imps.insert(prev);
				}

				if (cnt[cur] > 0 && cnt[cur] != s)
				{
					imps.insert(cur);
				}

				cnt[prev] = s;
				cnt[cur] = s;

				prev = cur;
			}
		}

		int answer = INF;
		int answerIndex = INF;

		if (imps.size() == 1)
		{
			answerIndex = *imps.begin();
		}
		else
		{
			for (const auto& src : imps)
			{
				VB visited(N + 1);
				visited[src] = true;
				queue<PII> q({ {0, src}});
				int cnt = imps.size() - 1;
				int sum = 0;
				while (!q.empty())
				{
					int cur = q.front().second;
					int step = q.front().first;
					q.pop();

					if (cur != src && imps.find(cur) != imps.end())
					{
						sum += step;
						cnt--;
					}

					if (!cnt)
						break;

					for (int next : adj[cur])
					{
						if (!visited[next])
						{
							visited[next] = true;
							q.push({ step + 1, next });
						}
					}
				}

				if (answer > sum)
				{
					answer = sum;
					answerIndex = src;
				}
				else if (answer == sum)
				{
					answerIndex = min(answerIndex, src);
				}
			}
		}

		cout << "Krochanska is in: " << answerIndex << '\n';
	}
	

	

	return 0;
}