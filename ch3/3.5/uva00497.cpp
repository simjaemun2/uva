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

using namespace std;

typedef long long int LL;

const int MAX_N = 1000000;

int tc, TC;
int N;

int A[MAX_N], L[MAX_N], L_id[MAX_N], P[MAX_N];

int my_lower_bound(int arr[], int size, int key)
{
	int left = 0;
	int right = size;

	while (left < right)
	{
		int mid = (left + right)/2;

		if (arr[mid] < key)
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

	string line;
	getline(cin, line);
	TC = stoi(line);
	getline(cin, line);

	for (int tc = 1; tc <= TC; tc++)
	{
		if (tc > 1)
		{
			cout << '\n';
		}

		int i = 0;
		int lis = 0, lis_end = 0;

		while (getline(cin, line) && line.size() > 0)
		{
			A[i] = stoi(line);
			int p = my_lower_bound(L, lis, A[i]);

			L[p] = A[i];
			L_id[p] = i;
			P[i] = p ? L_id[p - 1] : -1;

			if (p + 1 > lis)
			{
				lis = p + 1;
				lis_end = i;
			}

			i++;
		}

		cout << "Max hits: " << lis << '\n';

		stack<int> s;

		for (; P[lis_end] >= 0; lis_end = P[lis_end])
		{
			s.push(A[lis_end]);
		}

		cout << A[lis_end] << '\n';

		for (; !s.empty(); s.pop())
		{
			cout << s.top() << '\n';
		}
	}
	
	


	return 0;
}

