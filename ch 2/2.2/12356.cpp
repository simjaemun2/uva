#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_S 100000

int S, B;
int leftBound[MAX_S + 2];
int rightBound[MAX_S + 2];


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> S >> B)
	{
		if (S == 0)
			return 0;

		for (int i = 0; i <= S+1; i++)
		{
			leftBound[i] = i;
			rightBound[i] = i;
		}

		int l, r;

		for (int i = 0; i < B; i++)
		{
			int L, R;
			cin >> L >> R;
			
			l = leftBound[R] = L - 1;
			while (l != leftBound[l])
			{
				l = leftBound[R] = leftBound[l];
			}
				
			r = rightBound[L] = R + 1;
			while (r != rightBound[r])
			{
				r = rightBound[L] = rightBound[r];
			}

			if (l == 0)
				printf("%c ", '*');
			else
				printf("%d ", l);

			if (r == S + 1)
				printf("%c\n", '*');
			else
				printf("%d\n", r);
		}

		cout << "-\n";
	}
			

	

	return 0;
}