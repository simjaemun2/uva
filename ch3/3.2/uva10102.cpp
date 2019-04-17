#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2000000000;
const int MAX_DIGIT = 7;
const int MAX_D = 4;
int tc, TC;
int N;

struct Node {
	int y, x, min3;
	
	Node(int _y, int _x)
	{
		min3 = INF;
		y = _y;
		x = _x;
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
		vector<Node > color1;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				char c;
				cin >> c;
				v[i].push_back(c - '0');

				if (v[i][j] == 1)
				{
					color1.push_back(Node(i,j));
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (v[i][j] == 3)
				{
					for (int k=0; k<color1.size(); k++)
					{
						color1[k].min3 = min(color1[k].min3, abs(i - color1[k].y) + abs(j - color1[k].x));
					}
				}
			}
		}

		int answer = 0;

		for (Node n : color1)
		{
			answer = max(answer, n.min3);
		}
		
		cout << answer << '\n';
	}
	
	return 0;
}

