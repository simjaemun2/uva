#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

int TC,T,N;

int main(int argc, char** argv)
{
	
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		cin >> T >> N;

		for (int t = 0; t < T; t++)
		{
			int sr, sc, dr, dc;
			cin >> sr >> sc >> dr >> dc;

			if (sr == dr && sc == dc)
			{
				cout << "0\n";
				continue;
			}
				

			bool ssame = (sr & 1) == (sc & 1);
			bool dsame = (dr & 1) == (dc & 1);

			if (ssame == dsame)
			{
				if (abs(dr - sr) == abs(dc - sc))
					cout << "1\n";
				else
					cout << "2\n";
			}
			else
				cout << "no move\n";
		}
	}

	

	return 0;

}