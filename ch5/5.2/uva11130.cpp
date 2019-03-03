#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <string>

using namespace std;

double a,b,v,A,s;
#define M_PI       3.14159265358979323846

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	
	while (cin >> a >> b >> v >> A >> s, a)
	{
		double da = v*cos(M_PI * A / 180)*s/2;
		double db = v*sin(M_PI * A / 180)*s/2;

		double ta = round(da / a);
		double tb = round(db / b);

		cout << ta << ' ' << tb << '\n';
	}
	


	return 0;
}

