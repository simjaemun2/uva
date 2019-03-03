#define _CRT_SECURE_NO_WARNINGS 

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

using namespace std;

typedef long long int LL;

const int MAX_N = 20;
const int MAX_W = 200;

int tc, TC;
int N;
int input[MAX_N + 1];
int sum;
bool cache[MAX_W+1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	string line;
	getline(cin, line);
	TC = stoi(line);

	for (tc = 1; tc <= TC; tc++)
	{
		N = 0;
		sum = 0;
		
		getline(cin, line);
		istringstream iss(line);
		
		while (iss >> input[N])
		{
			sum += input[N++];
		}

		memset(cache, false, sizeof cache);
		cache[0] = true;

		if (sum % 2 == 0)
		{
			sum /= 2;

			for (int n = 0; n < N; n++)
			{
				for (int j = sum; j >= input[n]; j--)
				{
					cache[j] |= cache[j - input[n]];
				}
			}
		}

		cout << (cache[sum] ? "YES\n" : "NO\n");
	}


	return 0;
}

