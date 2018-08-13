#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

#define MAX_N 8
#define INF 1000000

int N;
double ans;
vector<int> ansVec;
bool selected[MAX_N + 1];
pair<int, int > input[MAX_N + 1];

double dist(int indexA, int indexB)
{
	double dx = input[indexA].first - input[indexB].first;
	double dy = input[indexA].second - input[indexB].second;
	return sqrt(dx*dx + dy*dy) + 16.0;
}

void traverse(int n, double sum, vector<int> vec)
{
	if (n == N)
	{
		if (sum < ans)
		{
			ans = sum;
			ansVec = vec;
		}
	}

	if (sum >= ans)
		return;

	int last = vec.back();

	for (int i = 0; i < N; i++)
	{
		if (selected[i])
			continue;

		selected[i] = true;
		vec.push_back(i);

		double len = dist(last, i);

		traverse(n + 1, sum + len, vec);

		selected[i] = false;
		vec.pop_back();
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 1;

	while (true)
	{
		scanf("%d", &N);
		if (!N)
			return 0;

		printf("**********************************************************\nNetwork #%d\n",tc++);
	
		for (int n = 0; n < N; n++)
			scanf("%d %d", &input[n].first, &input[n].second);
			
		ans = INF;
		vector<int> v;
		for (int n = 0; n < N; n++)
		{
			selected[n] = true;
			v.push_back(n);
			traverse(1, 0.0, v);
			v.pop_back();
			selected[n] = false;
		}

		for (int i = 1; i < ansVec.size(); i++)
		{
			int l = ansVec[i - 1];
			int h = ansVec[i];
			double len = dist(l, h);
			
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n"
				, input[l].first, input[l].second, input[h].first, input[h].second, len);
		}

		printf("Number of feet of cable required is %.2lf.\n", ans);
	}
	
	return 0;
}

