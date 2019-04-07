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


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

int tc, TC;
int N;

const int MAX_N = 100;

int input[MAX_N][MAX_N];

struct Node {
	int i, j, k;
	Node(int _i, int _j, int _k)
	{
		i = _i, j = _j, k = _k;
	}
};

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		vector<vector<int> > v(N);
		vector<Node> answer;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> input[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					if ((i < j && j < k || i > j && j > k)
						&& input[i][j] && input[j][k] && input[k][i])
					{
						answer.push_back(Node(i, j, k));
					}
					else if (i < j && j < k
						&& !input[i][j] && !input[j][k] && !input[k][i]
						&& !input[j][i] && !input[k][j] && !input[i][k])
					{
						answer.push_back(Node(i, j, k));
					}
				}
			}
		}

		cout << answer.size() << '\n';
		
		for (Node n : answer)
		{
			cout << n.i + 1 << ' ' << n.j + 1 << ' ' << n.k + 1 << '\n';
		}
	}



	return 0;
}
