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
const int MAX_N = 24;

int tc, TC;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	string line;
	while (getline(cin, line))
	{
		istringstream iss(line);
		string token;
		vector<int> v;
		int C = INT_MAX;

		while (iss >> token)
		{
			int w = 0;
			for (char c : token)
			{
				w <<= 5;
				w += c - 'a' + 1;
			}

			v.push_back(w);
			C = min(C, w);
		}

		int N = v.size();

		while (true)
		{
			int prevC = C;

			for (int i = 0; i < N && prevC == C; i++)
			{
				for (int j = i+1; j < N && prevC == C; j++)
				{
					if ((C / v[i]) % N == (C / v[j]) % N)
					{
						C = min((C / v[i] + 1) * v[i], (C / v[j] + 1) * v[j]);
					}
				}
			}

			if (prevC == C)
				break;
		}

		cout << line << '\n' << C << "\n\n";
	}

	
	
	return 0;
}