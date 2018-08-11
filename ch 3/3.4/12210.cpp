#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>



using namespace std;

#define MAX_B 60

int B, S;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;

	while (cin >> B >> S)
	{
		if (B == 0)
			break;

		cout << "Case " << tc++ << ": ";

		int minB = 99999999;

		for (int i = 0; i < B; i++)
		{
			int b;
			cin >> b;
			minB = min(b, minB);
		}
			

		for (int i = 0; i < S; i++)
		{
			int s;
			cin >> s;
		}
			

		if (B <= S)
		{
			cout << "0\n";
		}
		else
		{
			cout << B - S << ' ' << minB << '\n';
		}
	}
				

	return 0;
}

