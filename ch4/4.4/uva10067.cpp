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
int DY[] = { -1,1,0,0,0,0 };
int DX[] = { 0,0,-1,1,0,0 };
int DZ[] = { 0,0,0,0,-1,1 };

const int MAX_D = 4;
const int MAX_N = 100;

int buttons[MAX_N][MAX_D];
int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	cin >> TC;
	for(tc=1;tc<=TC;tc++)
	{
		string src(MAX_D, ' '), dst(MAX_D, ' ');
		set<string> s({src});

		for (int i = 0; i < MAX_D; i++)
		{
			cin >> src[i];
		}
		for (int i = 0; i < MAX_D; i++)
		{
			cin >> dst[i];
		}

		cin >> N;

		for (int n = 0; n < N; n++)
		{
			string forbidden(MAX_D, ' ');
			
			for (int i = 0; i < MAX_D; i++)
			{
				cin >> forbidden[i];
			}

			s.insert(forbidden);
		}
		
		int answer = -1;

		queue<pair<int, string> > q;
		q.push({ 0, src });

		while (!q.empty())
		{
			string cur = q.front().second;
			int step = q.front().first;
			q.pop();

			if (cur == dst)
			{
				answer = step;
				break;
			}

			for (int d = 0; d < MAX_D; d++)
			{
				string next = cur;
				char t = next[d];
				t = (t - '0' + 1) % 10 + '0';
				next[d] = t;

				if (s.find(next) == s.end())
				{
					s.insert(next);
					q.push({ step + 1, next });
				}

				next = cur;
				t = next[d];
				t = (t - '0' - 1 + 10) % 10 + '0';
				next[d] = t;

				if (s.find(next) == s.end())
				{
					s.insert(next);
					q.push({ step + 1, next });
				}
			}
		}


		cout << answer << '\n';
	}


	return 0;
}