#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

#define MAX_N 10000


int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int T,tc;
	cin >> T;
	getchar();
	getchar();
	for (tc = 0; tc < T; tc++)
	{
		if(tc != 0)
			cout << '\n';

		int cnt = 0;
		map<string, int> m;
		string input;
		
		while (getline(cin, input))
		{
			if (input.compare("") == 0)
				break;
			m[input]++;
			cnt++;
		}
		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
			cout << it->first << " " << fixed << setprecision(4) << it->second*100.0 / cnt << '\n';
		
	}
	
	return 0;
}