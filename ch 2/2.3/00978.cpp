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
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

#define MAX_N 5000

int N,B,SB,SG;


int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> N;

	while (N--)
	{
		cin >> B >> SG >> SB;

		multiset<int, greater<int> > msg, msb;
		vector<int> survivors;
		int a;

		for (int i = 0; i < SG; i++)
		{
			cin >> a;
			msg.insert(a);
		}

		for (int i = 0; i < SB; i++)
		{
			cin >> a;
			msb.insert(a);
		}

		while (!msb.empty() && !msg.empty())
		{
			
			for (int s = 0; s < B && !msb.empty() && !msg.empty(); s++)
			{
				survivors.push_back(*msb.begin() - *msg.begin());
				msb.erase(msb.begin());
				msg.erase(msg.begin());
			}

			for (auto s : survivors)
			{
				if (s > 0)
					msb.insert(s);
				else if (s < 0)
					msg.insert(-s);
			}

			survivors.clear();
		}

		if (msb.size() == 0 && msg.size() == 0)
			cout << "green and blue died\n";
		else
		{
			multiset<int, greater<int> >::iterator start, end;
		
			if (msb.size() > 0)
			{
				cout << "blue wins\n";
				start = msb.begin();
				end = msb.end();
			}
			else
			{
				cout << "green wins\n";
				start = msg.begin();
				end = msg.end();
			}

			for (; start != end; start++)
				cout << *start << '\n';
		}
		if(N)
			cout << '\n';
	}

	
	return 0;
}