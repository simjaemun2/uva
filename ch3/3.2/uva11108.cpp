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
const int MAX_N = 3000;


int tc, TC;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	string line;
	
	while (cin >> line, line[0] != '0')
	{
		bool isPossible = true;

		for (int p = 0; p <= 1 && isPossible; p++)
		{
			for (int q = 0; q <= 1 && isPossible; q++)
			{
				for (int r = 0; r <= 1 && isPossible; r++)
				{
					for (int s = 0; s <= 1 && isPossible; s++)
					{
						for (int t = 0; t <= 1 && isPossible; t++)
						{
							stack<int> operands;
							int op1, op2;
							for (int i = line.size() - 1; i >= 0; i--)
							{
								if (line[i] == 'p')
									operands.push(p);
								else if (line[i] == 'q')
									operands.push(q);
								else if (line[i] == 'r')
									operands.push(r);
								else if (line[i] == 's')
									operands.push(s);
								else if (line[i] == 't')
									operands.push(t);
								else if (line[i] == 'K')
								{
									op2 = operands.top();
									operands.pop();
									op1 = operands.top();
									operands.pop();
									operands.push(op1&op2);
								}
								else if (line[i] == 'A')
								{
									op2 = operands.top();
									operands.pop();
									op1 = operands.top();
									operands.pop();
									operands.push(op1|op2);
								}
								else if (line[i] == 'N')
								{
									op2 = operands.top();
									operands.pop();
									operands.push(!op2);
								}
								else if (line[i] == 'C')
								{
									op2 = operands.top();
									operands.pop();
									op1 = operands.top();
									operands.pop();
									operands.push(!(op1 && op1 != op2));
								}
								else if (line[i] == 'E')
								{
									op2 = operands.top();
									operands.pop();
									op1 = operands.top();
									operands.pop();
									operands.push(op1 == op2);
								}
								
							}

							if (!operands.top())
								isPossible = false;
						}
					}
				}
			}
		}

		cout << (isPossible ? "tautology\n" : "not\n");
	}

	return 0;
}
