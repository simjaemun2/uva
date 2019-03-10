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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_M = 5000;

int tc, TC;
int N, M;

struct Node{
	int idx, size;
	vector<int> v;
};

bool compare(const PII& a, const PII& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> M >> N, M)
	{
		vector<PII> vn(N), vm(M);
		for (int m = 0; m < M; m++)
		{
			cin >> vm[m].first;
			vm[m].second = m + 1;
		}

		for (int n = 0; n < N; n++)
		{
			cin >> vn[n].first;
			vn[n].second = n + 1;
		}

		sort(vm.begin(), vm.end(), compare);
		sort(vn.begin(), vn.end());

		map<int, vector<int> > mv;
		
		bool isPossible = true;


		int start = 0;
		for (int m = 0; m < M; m++)
		{
			if (N - start < vm[m].first)
			{
				isPossible = false;
				break;
			}

			int acc = 0;

			for (int i = 0; i < vm[m].first; i++)
			{
				mv[vm[m].second].push_back(vn[start + i].second);
				vn[start + i].first--;
				if (!vn[start + i].first)
				{
					acc++;
				}
			}

			start += acc;
		}
		
		if (!isPossible)
		{
			cout << "0\n";
		}
		else
		{
			cout << "1\n";

			for (int i = 1; i <= M; i++)
			{
				sort(mv[i].begin(), mv[i].end());

				for (int a : mv[i])
				{
					cout << a << ' ';
				}

				cout << '\n';
			}
		}
	}
	
	


	return 0;
}