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

int N;

int main(int argc, char** argv)
{
	string line;

	while (true)
	{
		getline(cin, line);

		N = stoi(line);

		if (!N)
			break;

		int answer = 0;
		int minCnt = 25;
		for (int n = 0; n < N; n++)
		{
			int cnt = 0;
			getline(cin, line);
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == ' ')
				{
					cnt++;
				}
			}
			answer += cnt;
			minCnt = min(cnt, minCnt);
		}
	
		cout << answer - N * minCnt << '\n';
	}
	

	return 0;

}