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


const int INF = 987654321;
const int MAX_N = 100;

int tc, TC;
int N,M;

bool org[MAX_N];
bool candi[MAX_N];
vector<vector<int> > adj;

void traverse(bool arr[], int skip)
{
	memset(arr, false, sizeof org);

	queue<int> q;
	q.push(0);
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur != skip)
		{
			arr[cur] = true;
			for (int next : adj[cur])
			{
				if (!arr[next])
				{
					q.push(next);
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;

		adj = vector<vector<int> >(N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a;
				
				cin >> a;
				
				if (a)
				{
					adj[i].push_back(j);
				}
				
			}
		}


		cout << "Case " << tc << ":\n+" << string(2 * N - 1, '-') << "+\n";

		traverse(org, -1);

		for (int i = 0; i < N; i++)
		{
			traverse(candi, i);

			cout << '|';

			for (int j = 0; j < N; j++)
			{
				cout << (org[j] != candi[j] ? "Y|" : "N|");
			}

			cout << "\n+" << string(2 * N - 1, '-') << "+\n";
		}
	}
	

	
	return 0;
}

