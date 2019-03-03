#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string S;
string SS;
int Q;
vector<int> index[100];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> S;

	for (int i = 0; i < S.size(); i++)
	{
		index[S[i] - 'A'].push_back(i);
	}

	cin >> Q;
	while (Q--)
	{
		cin >> SS;
		int ssindex = 0;
		int sindex = 0;
		
		int l = -1, r;

		for (;ssindex < SS.size(); ssindex++)
		{
			int c = SS[ssindex] - 'A';

			auto indexInVector = lower_bound(index[c].begin(), index[c].end(), sindex);

			if (indexInVector == index[c].end())
				break;
			
			if (l == -1)
				l = *indexInVector;
			
			r = *indexInVector;
			
			sindex = r + 1;
		}


		if (ssindex == SS.size())
		{
			cout << "Matched " << l << ' ' << r << '\n';
		}
		else
		{
			cout << "Not matched\n";
		}
		/*
		if (Q > 0)
			cout << '\n';
			*/
	}
	

	return 0;
}

