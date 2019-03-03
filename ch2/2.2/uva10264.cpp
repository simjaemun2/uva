#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

#define MAX_N 15
#define MAX_WEIGHT 256
//1<<8

int N;
int weight[1 << 15];
int adj[1 << 15];

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> N)
	{
		int sum = 0;
		for (int i = 0; i < (1 << N); i++)
		{
			cin >> weight[i];
			adj[i] = 0;
		}
		
		for (int i = 0; i < (1 << N); i++)
		{			
			for (int j = 0; j < N; j++)
			{
				adj[i] += weight[i ^ (1 << j)];
			}
		}

		int result = 0;

		for (int i = 0; i < (1 << N); i++)
		{
			for (int j = 0; j < N; j++)
			{
				result = max(result, adj[i] + adj[i ^ (1 << j)]);
			}
		}

		cout << result << '\n';
	}

	return 0;
}