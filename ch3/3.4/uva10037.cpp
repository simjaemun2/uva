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

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

const int INF = 2000000000;
const int MAX_M = 5000;

int tc, TC;
int N;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> TC;

	for(tc=1; tc<=TC; tc++)
	{
		if (tc > 1)
			cout << '\n';
		cin >> N;

		vector<int> v(N+1);
		v[0] = 0;
		for (int n = 1; n <= N; n++)
		{
			cin >> v[n];
		}

		sort(v.begin(), v.end());

		int tail = N;
		int sum = 0;
		stringstream iss;
		while (tail >= 4)
		{
			int c1 = v[2]
				+ v[1]
				+ v[tail]
				+ v[2];
			
			int c2 = v[tail]
				+ v[1]
				+ v[tail - 1]
				+ v[1];

			if (c1 < c2)
			{
				sum += c1;
				iss << v[1] << ' ' << v[2] << '\n'
					<< v[1] << '\n'
					<< v[tail - 1] << ' ' << v[tail] << '\n'
					<< v[2] << '\n';
			}
			else
			{
				sum += c2;
				iss << v[1] << ' ' << v[tail] << '\n'
					<< v[1] << '\n'
					<< v[1] << ' ' << v[tail - 1] << '\n'
					<< v[1] << '\n';
			}

			tail -= 2;
		}

		if (tail == 3)
		{
			sum += v[3] + v[1] + v[2];
			iss << v[1] << ' ' << v[3] << '\n'
				<< v[1] << '\n'
				<< v[1] << ' ' << v[2] << '\n';
		}
		else if (tail == 2)
		{
			sum += v[2];
			iss << v[1] << ' ' << v[2] << '\n';
		}
		else // tail == 1
		{
			sum += v[1];
			iss << v[1] << '\n';
		}

		cout << sum << '\n' << iss.str();
	}
	
	


	return 0;
}