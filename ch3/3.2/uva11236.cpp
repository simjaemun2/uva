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


const int INF = 2000000000;
const int MAX_N = 2000;

int tc, TC;
double FROM, TO;

struct Node {
	double s, a, b, c,d;
};

bool compare(const Node& a, const Node& b)
{
	return a.s < b.s;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	vector<Node> v;

	for (int a = 1; 4*a < MAX_N; a++)
	{
		for (int b = a; a+3*b < MAX_N; b++)
		{
			for (int c = b; a+b+c*2<MAX_N; c++)
			{
				if (a*b*c <= 1000000)
				{
					continue;
				}

				int d = 1000000 * (a + b + c) / (a*b*c - 1000000);

				if (c > d || a+b+c+d > MAX_N)
				{
					continue;
				}

				if (a*b*c*d == (a + b + c + d) * 1000000)
				{
					Node n;
					n.a = a / 100.0;
					n.b = b / 100.0;
					n.c = c / 100.0;
					n.d = d / 100.0;
					n.s = (a + b + c + d) / 100.0;
					v.push_back(n);
				}
			}
		}
	}

	for (Node n : v)
	{
		printf("%.2f %.2f %.2f %.2f\n", n.a, n.b, n.c, n.d);
	}

	

	return 0;
}
