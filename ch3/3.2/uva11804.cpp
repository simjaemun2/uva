#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2000000000;
const int MAX_N = 10;

int tc, TC;


struct Node {
	string name;
	int a, d;
};

bool compare(const Node& a, const Node& b)
{
	return a.name < b.name;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;
	
	for (tc = 1; tc <= TC; tc++)
	{
		vector<Node> v(MAX_N);

		int sumD = 0;

		for (int n = 0; n < MAX_N; n++)
		{
			cin >> v[n].name >> v[n].a >> v[n].d;
			sumD += v[n].d;
		}

		sort(v.begin(), v.end(), compare);

		int A, B, C, D, E;
		int maxA = 0, maxD = 0;

		for (int a = 0; a < MAX_N - 4; a++)
		{
			for (int b = a + 1; b < MAX_N - 3; b++)
			{
				for (int c = b + 1; c < MAX_N - 2; c++)
				{
					for (int d = c + 1; d < MAX_N - 1; d++)
					{
						for (int e = d + 1; e < MAX_N; e++)
						{
							if (maxA < v[a].a + v[b].a + v[c].a + v[d].a + v[e].a
								|| maxA == v[a].a + v[b].a + v[c].a + v[d].a + v[e].a && maxD < sumD - (v[a].d + v[b].d + v[c].d + v[d].d + v[e].d))
							{
								maxA = v[a].a + v[b].a + v[c].a + v[d].a + v[e].a;
								maxD = sumD - (v[a].d + v[b].d + v[c].d + v[d].d + v[e].d);
								A = a, B = b, C = c, D = d, E = e;
							}
						}
					}
				}
			}
		}

		cout << "Case " << tc << ":\n(";
		
		bool isFirst = true;
		
		for (int i = 0; i < MAX_N; i++)
		{
			if (i == A || i == B || i == C || i == D || i == E)
			{
				if (!isFirst)
				{
					cout << ", ";
				}
				isFirst = false;
				cout << v[i].name;
			}
		}

		cout << ")\n(";

		isFirst = true;
		
		for (int i = 0; i < MAX_N; i++)
		{
			if (!(i == A || i == B || i == C || i == D || i == E))
			{
				if (!isFirst)
				{
					cout << ", ";
				}
				isFirst = false;
				cout << v[i].name;
			}
		}

		cout << ")\n";
	}
	
	return 0;
}

