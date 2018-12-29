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

int main(int argc, char** argv)
{
	string line;
	getline(cin, line);
	int tc = stoi(line);

	while (tc--)
	{
		getline(cin, line);
		getline(cin, line);

		vector<pair<int, string> > v;

		int i;
		istringstream iss(line);
		
		while (iss >> i)
		{
			v.push_back({ i, "" });
		}

		getline(cin, line);

		iss = istringstream(line);

		string token;
		i = 0;
		while (iss >> token)
		{
			v[i++].second = token;
		}

		sort(v.begin(), v.end());

		for (auto p : v)
		{
			cout << p.second << '\n';
		}

		if(tc)
			cout << '\n';
	}
	
	return 0;

}