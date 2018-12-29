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

bool isPossible(vector<int>& datas, int& t)
{
	for (int d : datas)
	{
		if (t % (d * 2) >= d - 5)
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	string line;

	int tc = 1;

	const int MAX_T = 3600;

	while (getline(cin, line))
	{
		istringstream iss(line);
		
		int t;
		int minTime = 90;
		vector<int> datas;

		while (iss >> t)
		{
			datas.push_back(t);
			minTime = min(t, minTime);
		}

		int answer;
		for (answer = minTime * 2; !isPossible(datas, answer) && answer <= MAX_T; answer++);

		cout << "Set " << tc++ << ' ';

		if (answer == MAX_T + 1)
		{
			cout << "is unable to synch after one hour.\n";
		}
		else
		{
			cout << "synchs again at " << answer / 60
				<< " minute(s) and " << answer % 60
				<< " second(s) after all turning green.\n";
		}
	}
	
	return 0;

}