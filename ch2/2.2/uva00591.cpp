#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

#define MAX_N 50
int input[MAX_N];
int N;

int main(int argc, char** argv)
{
	int tc = 1;

	while (cin >> N, N)
	{
		int sum = 0;

		int answer = 0;

		for (int n = 0; n < N; n++)
		{
			cin >> input[n];
			sum += input[n];
		}

		sum /= N;

		for (int n = 0; n < N; n++)
		{
			answer += abs(sum - input[n]);
		}

		cout << "Set #" << tc++ << '\n'
			<< "The minimum number of moves is " << answer/2 << ".\n\n";

	}
	
	return 0;

}