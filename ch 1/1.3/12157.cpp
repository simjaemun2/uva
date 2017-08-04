#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define DA 30
#define DB 60
#define MA 10
#define MB 15

int N,M,A,B;

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	cin >> T;

	for (tc = 0; tc < T; tc++)
	{
		cin >> N;
		A = B = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> M;
			A += (M / DA + 1)*MA;
			B += (M / DB + 1)*MB;
		}

		cout << "Case " << (tc + 1) << ": ";

		//Mile Juice 60

		if (A < B)
			cout << "Mile " << A << '\n';
		else if(A > B)
			cout << "Juice " << B << '\n';
		else
			cout << "Mile Juice " << B << '\n';
	}

	return 0;
}