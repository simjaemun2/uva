#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 9;
const int INF = 2000000000;
int input[MAX_N];



int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	//012 345 678
	//BGC BGC BGC
	while (cin >> input[0])
	{
		for (int i = 1; i < MAX_N; i++)
			cin >> input[i];

		int answer = INF;
		string result;
		//BCG
		if (answer > input[1] + input[2] + input[3] + input[4] + input[6] + input[8])
		{
			answer = input[1] + input[2] + input[3] + input[4] + input[6] + input[8];
			result = "BCG ";
		}

		//BGC
		if (answer > input[1] + input[2] + input[3] + input[5] + input[6] + input[7])
		{
			answer = input[1] + input[2] + input[3] + input[5] + input[6] + input[7];
			result = "BGC ";
		}

		//CBG
		if (answer > input[0] + input[1] + input[4] + input[5] + input[6] + input[8])
		{
			answer = input[0] + input[1] + input[4] + input[5] + input[6] + input[8];
			result = "CBG ";
		}

		//CGB
		if (answer > input[0] + input[1] + input[3] + input[5] + input[7] + input[8])
		{
			answer = input[0] + input[1] + input[3] + input[5] + input[7] + input[8];
			result = "CGB ";
		}

		//GBC
		if (answer > input[0] + input[2] + input[4] + input[5] + input[6] + input[7])
		{
			answer = input[0] + input[2] + input[4] + input[5] + input[6] + input[7];
			result = "GBC ";
		}

		//GCB
		if (answer > input[0] + input[2] + input[3] + input[4] + input[7] + input[8])
		{
			answer = input[0] + input[2] + input[3] + input[4] + input[7] + input[8];
			result = "GCB ";
		}

		cout << result << answer << '\n';
	}
	
	return 0;
}

