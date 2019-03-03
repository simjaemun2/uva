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

int my_lower_bound(vector<pair<int, int> >& v, int key)
{
	int left = 0, right = v.size();

	while (left < right)
	{
		int mid = (left + right) / 2;
		
		if (v[mid].first < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return right;
}

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

		vector<int> H(N), W(N), LIS(N), LDS(N);

		for (int n = 0; n < N; n++)
		{
			cin >> H[n];
		}

		for (int n = 0; n < N; n++)
		{
			cin >> W[n];
			LIS[n] = LDS[n] = W[n];
		}
		
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (H[i] > H[j])
				{
					LIS[i] = max(LIS[i], LIS[j] + W[i]);
				}

				if (H[i] < H[j])
				{
					LDS[i] = max(LDS[i], LDS[j] + W[i]);
				}
			}
		}

		int max_lis = *max_element(begin(LIS), end(LIS));
		int max_lds = *max_element(begin(LDS), end(LDS));


		cout << "Case " << tc << ". ";
		
		if (max_lis >= max_lds)
		{
			cout << "Increasing (" << max_lis << "). Decreasing (" << max_lds << ").\n";
		}
		else
		{
			cout << "Decreasing (" << max_lds << "). Increasing (" << max_lis << ").\n";
		}
		
	}


	return 0;
}

