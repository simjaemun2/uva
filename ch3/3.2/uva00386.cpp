#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2000000000;
const int MAX_DIGIT = 7;
const int MAX_D = 4;
int tc, TC;
int N;


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	for (int a = 6; a <= 200; a++)
	{
		for (int b = 2; b < a; b++)
		{
			for (int c = b+1; c < a; c++)
			{
				for (int d = c+1; d < a; d++)
				{
					if (a * a * a == b * b * b + c * c * c + d * d * d)
					{
						cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ")\n";
					}
				}
			}
		}
	}
	
	return 0;
}

