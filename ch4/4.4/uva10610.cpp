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
//int DY[] = { -1,0,1,0,-1,-1,1,1 };
//int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 5;
int N, M;

string FINAL = "111110111100 110000100000";

struct Node {
	int d;
	int y;
	int x;
	string board;
};
const int MAX_D = 8;
int DY[MAX_D] = { -1, -2, -2, -1, 1, 2,  2,  1 };
int DX[MAX_D] = { -2, -1,  1,  2, 2, 1, -1, -2 };

double getDist(const PDD& a, const PDD& b)
{
	return hypot(a.first - b.first, a.second - b.second);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	string line;
	getline(cin, line);
	istringstream iss(line);
	
	while (iss >> N >> M, N | M)
	{
		vector<PDD > v(2);
		VVI adj(2);
		double maxDist = (double)N * M * 60;
		
		getline(cin, line);
		iss = istringstream(line);
		iss >> v[0].first >> v[0].second;
		
		getline(cin, line);
		iss = istringstream(line);
		iss >> v[1].first >> v[1].second;

		if (getDist(v[0], v[1]) <= maxDist)
		{
			adj[0].push_back(1);
			adj[1].push_back(0);
		}

		while (getline(cin, line), line.size())
		{
			iss = istringstream(line);
			double x, y;
			iss >> x >> y;
			VI nv;
			PDD np = { x,y };

			for (int i = 0; i < v.size(); i++)
			{
				if (getDist(v[i], np) <= maxDist)
				{
					adj[i].push_back(v.size());
					nv.push_back(i);
				}
			}

			adj.push_back(nv);
			v.push_back(np);
		}

		queue<PII> q;
		VB visited(v.size());
		visited[0] = true;
		q.push({ 0, 0 });

		int answer = -1;

		while (!q.empty())
		{
			int cur = q.front().second;
			int step = q.front().first;
			q.pop();

			if (cur == 1)
			{
				answer = step;
				break;
			}

			for (int next : adj[cur])
			{
				if (!visited[next])
				{
					visited[next] = true;
					q.push({ step + 1, next });
				}
			}
		}

		if (answer == -1)
		{
			cout << "No.\n";	
		}
		else
		{
			cout << "Yes, visiting " << answer - 1 << " other holes.\n";
		}

		getline(cin, line);
		iss = istringstream(line);
	}


	return 0;
}