#define _CRT_SECURE_NO_WARNINGS 

#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int VT,VZ;

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (cin >> VT >> VZ, VT | VZ)
	{
		int answer = 0;
		double maxD = 0.0;
		int V;
		for (int p = 1; p <= VT ; p++)
		{
			double V = (double)VT / p;
			if (V <= VZ)
				break;
			double d = 0.3 * sqrt(V - VZ) * p;

			if (fabs(d - maxD) < 1e-12)
			{
				answer = 0;
			}
			else if (d > maxD)
			{
				maxD = d;
				answer = p;
			}
			else
			{
				break;
			}
		}
		
		cout << answer << '\n';
		
	}


	
	return 0;
}

