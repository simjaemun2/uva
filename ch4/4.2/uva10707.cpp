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
const int MAX_N = 9;
const int MAX_D = 4;
const int MAX_WH = 100;

int tc, TC;
int W, H, N;

int DY[] = { -1,0,1,0,-1,-1,1,1};
int DX[] = { 0,-1,0,1,-1,1,-1,1};

bool graph[2][MAX_WH][MAX_WH];
int sum[2][MAX_WH * MAX_WH];

int L[MAX_WH][MAX_WH];
int R[MAX_WH][MAX_WH];
int U[MAX_WH][MAX_WH];
int D[MAX_WH][MAX_WH];


void cal(bool g[][MAX_WH], int sum[])
{
	for (int h = 0; h < H; h++)
	{
		for (int w = 0, c = 0; w < W; w++)
		{
			c = g[h][w] ? c + 1 : 0;
			L[h][w] = c;
		}
	}

	for (int h = 0; h < H; h++)
	{
		for (int w = W-1, c = 0; w >= 0; w--)
		{
			c = g[h][w] ? c + 1 : 0;
			R[h][w] = c;
		}
	}

	for (int w = 0; w < W; w++)
	{
		for (int h = 0, c = 0; h < H; h++)
		{
			c = g[h][w] ? c + 1 : 0;
			U[h][w] = c;
		}
	}

	for (int w = 0; w < W; w++)
	{
		for (int h = H-1, c = 0; h >= 0; h--)
		{
			c = g[h][w] ? c + 1 : 0;
			D[h][w] = c;
		}
	}

	int c = 0;

	for (int h = 0; h < H; h++)
	{
		for (int w = 0; w < W; w++)
		{
			if (g[h][w])
			{
				sum[c++] = L[h][w] + R[h][w] + U[h][w] + D[h][w];
			}
		}
	}

	sort(sum, sum + c);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> TC;
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> W >> H >> N;
		
		memset(graph, false, sizeof graph);
		
		for (int i = 0; i < 2; i++)
		{
			for (int n = 0; n < N; n++)
			{
				int x, y;
				cin >> x >> y;
				graph[i][y][x] = true;
			}

			cal(graph[i], sum[i]);
		}

		int n = 0;
		for (; n < N; n++)
		{
			if (sum[0][n] != sum[1][n])
			{
				break;
			}
		}

		cout << (n == N ? "YES\n" : "NO\n");
	}

	return 0;
}



