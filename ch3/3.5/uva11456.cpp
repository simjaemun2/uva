#define _CRT_SECURE_NO_WARNINGS 

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

using namespace std;

typedef long long int LL;

const int MAX_N = 10000;

int tc, TC;
int N;
int input[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;

	for (tc = 1; tc <= TC; tc++)
	{
		cin >> N;
		
		if (!N)
		{
			cout << "0\n";
			continue;
		}

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
		}

		vector<int> lis(1, -1);
		vector<int> lds(1, -987654321);
		vector<int> answer(N);

		for (int n = N-1; n >= 0; n--)
		{
			if (lis.back() < input[n])
			{
				lis.push_back(input[n]);
				answer[n] += lis.size() - 1;
			}
			else
			{
				auto it = lower_bound(lis.begin(), lis.end(), input[n]);
				*it = input[n];
				answer[n] += it - lis.begin();
			}

			if (lds.back() < -input[n])
			{
				lds.push_back(-input[n]);
				answer[n] += lds.size() - 1;
			}
			else
			{
				auto it = lower_bound(lds.begin(), lds.end(), -input[n]);
				*it = -input[n];
				answer[n] += it - lds.begin();
			}
		}

		cout << *max_element(answer.begin(), answer.end()) -1 << '\n';		
	}


	return 0;
}

