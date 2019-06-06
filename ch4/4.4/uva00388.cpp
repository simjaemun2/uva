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
int DY[] = { -1,0,1,0,-1,-1,1,1 };
int DX[] = { 0,-1,0,1,-1,1,-1,1 };

const int MAX_N = 1000000;
int N, M;



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif
	
	//tc = 1;
	
	while (cin >> N)

	//cin >> TC;
	//for(tc=1;tc<=TC;tc++)
	{
		/*
		if (tc != 1)
			cout << '\n';
			*/

		map<char, vector<char> > adj;
		map<char, double > values;
		
		for (int n = 0; n < N; n++)
		{
			char src;
			double d;
			string s;

			cin >> src >> d >> s;

			for (char des : s)
			{
				adj[src].push_back(des);
			}

			values[src] = d;
		}

		double maxDist = 0;
		char answer;

		for (auto it : values)
		{
			map<char, bool > visited;

			priority_queue<pair<double, char> > pq;
			pq.push({ it.second, it.first });
			visited[it.first] = true;
			bool isAnswer = false;
			
			while (!pq.empty() && !isAnswer)
			{
				char cur = pq.top().second;
				double dist = pq.top().first;
				pq.pop();
				for (char next : adj[cur])
				{
					if (next == '*')
					{
						if (maxDist < dist)
						{
							maxDist = dist;
							answer = it.first;
						}

						isAnswer = true;
						break;
					}
					else
					{
						if (!visited[next])
						{
							visited[next] = true;
							pq.push({ dist*0.95, next });
						}
						
					}
				}
			}
		}

		cout << "Import from " << answer << '\n';
	}


	return 0;
}