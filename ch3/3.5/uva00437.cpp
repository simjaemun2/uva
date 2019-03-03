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

using namespace std;

typedef long long int LL;

const int MAX_N = 30;

int N;

struct Node {
	LL y, x, h, size;
	Node();
	Node(LL _y, LL _x, LL _h)
	{
		y = _y;
		x = _x;
		h = _h;
		size = y * x;
	}

	bool operator<(const Node& b) const
	{
		return tie(y, x, h) < tie(b.y, b.x, b.h);
	}
};



bool compare2(const Node& a, const Node& b)
{
	if (a.size == b.size)
		return a.h > b.h;
	return a.size > b.size;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;
	
	while (cin >> N, N)
	{
		set<Node> s;

		for (int n = 0; n < N; n++)
		{
			LL arr[3];
			cin >> arr[0] >> arr[1] >> arr[2];

			for (int i = 0; i < 6; i++)
			{
				s.insert(Node(arr[0], arr[1], arr[2]));
				next_permutation(arr, arr + 3);
			}
		}

		vector<Node> v(s.begin(), s.end());

		sort(v.begin(), v.end(), compare2);

		vector<LL> cache(v.size() + 1);

		cache[0] = v[0].h;

		for (int i = 1; i < v.size(); i++)
		{
			cache[i] = v[i].h;
			for (int  j = 0; j < i; j++)
			{
				if (v[i].x < v[j].x && v[i].y < v[j].y && cache[i] < cache[j] + v[i].h)
				{
					cache[i] = cache[j] + v[i].h;
				}
			}
		}


		cout << "Case " << tc++ << ": maximum height = "
			<< *max_element(cache.begin(), cache.end()) << '\n';

	}
	return 0;
}

