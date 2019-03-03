#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N, X;


int main(int argc, char** argv)
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		int N;
		cin >> N;

		cout << abs(((N * 567 / 9 + 7492) * 235 / 47 - 498)/10 % 10) << '\n';
	}
	

	return 0;

}