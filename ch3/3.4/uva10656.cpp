#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>



using namespace std;

#define MAX_N 1000

int N;
int NN[MAX_N + 1];


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		
		int first = -1;
		int last = -1;

		for (int i = 0; i < N; i++)
		{
			cin >> NN[i];

			if(NN[i] != 0)
			{
				if (first == -1)
					first = i;
				last = i;
			}
		}
			
		if (first == -1)
			cout << "0\n";
		else
		{
			for (int i = first; i < last; i++)
			{
				if(NN[i] > 0)
					cout << NN[i] << ' ';
			}
			cout << NN[last] << '\n';
		}
	}
	
	
				

	return 0;
}

