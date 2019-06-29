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

const int MAX_N = 10;
const int MAX_K = 30;
int K,N;

int boxes[MAX_K+1][MAX_N];
bool visited[MAX_K+1];
bool findAnswer;

VI tstack;
int answerCnt;
VI answer(MAX_K+1);

void rec(int ck)
{
	int cnt = 0;

	for (int nk = 1; nk <= K; nk++)
	{
		if (!visited[nk])
		{
			int i = 0;
			for (; i < N; i++)
			{
				if (boxes[ck][i] >= boxes[nk][i])
				{
					break;
				}
			}

			if (i == N)
			{
				tstack.push_back(nk);
				visited[nk] = true;
				rec(nk);
				visited[nk] = false;
				tstack.pop_back();
			}
		}
		else
		{
			cnt++;
		}
	}

	if (answerCnt < cnt)
	{
		answerCnt = cnt;
		for (int i = 0; i < answerCnt; i++)
		{
			answer[i] = tstack[i];
		}
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> K >> N)
	{
		for (int k = 1; k <= K; k++)
		{
			for (int n = 0; n < N; n++)
			{
				cin >> boxes[k][n];
			}

			sort(boxes[k], boxes[k] + N);
		}

		answerCnt = 0;

		for (int k = 1; k <= K; k++)
		{
			tstack.push_back(k);
			visited[k] = true;
			rec(k);
			visited[k] = false;
			tstack.pop_back();
		}

		cout << answerCnt << '\n';
		for (int i = 0; i < answerCnt; i++)
		{
			if (i)
				cout << ' ';

			cout << answer[i];
		}
		cout << '\n';
	}

	return 0;
}
