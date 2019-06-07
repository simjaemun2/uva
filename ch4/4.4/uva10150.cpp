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


int N;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	string line;

	VS v;
	VVI adj;
	map<string, int> m;

	while (getline(cin, line), line.size())
	{
		m[line] = N++;
		v.push_back(line);
		
		VI nv;

		for (int n = 0; n < N - 1; n++)
		{
			if (v[n].size() == line.size())
			{
				int index = -1;
				int cnt = 0;
				for (int i = 0; i < v[n].size(); i++)
				{
					if (v[n][i] != line[i])
					{
						index = i;
					}
					else
					{
						cnt++;
					}
				}

				if (cnt == v[n].size() - 1)
				{
					adj[n].push_back(N - 1);
					nv.push_back(n);
				}
			}
		}

		adj.push_back(nv);
	}
	
	tc = 1;
	while (getline(cin, line))
	{
		if (tc != 1)
			cout << '\n';
		tc++;
		istringstream iss(line);
		string us, vs;
		iss >> us >> vs;
		
		if (us.size() != vs.size())
		{
			cout << "No solution.\n";
		}
		else
		{
			queue<pair<int, string> > q({ {m[us],us} });
			VB visited(N);
			visited[m[us]] = true;
			bool hasAnswer = false;
			while (!q.empty() && !hasAnswer)
			{
				int cur = q.front().first;
				string path = q.front().second;
				q.pop();

				if (cur == m[vs])
				{
					cout << path << '\n';
					hasAnswer = true;
					break;
				}

				for (int next : adj[cur])
				{
					if (!visited[next])
					{
						visited[next] = true;
						q.push({ next, path + '\n' + v[next] });
					}
				}
			}

			if (!hasAnswer)
			{
				cout << "No solution.\n";
			}
		}
	}



	return 0;
}