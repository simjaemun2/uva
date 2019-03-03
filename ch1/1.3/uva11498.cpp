#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

int DX,DY,x,y,N;

void printResult()
{
	if (x == DX || y == DY)
		cout << "divisa\n";
	else if (x > DX)
		if (y > DY)
			cout << "NE\n";
		else
			cout << "SE\n";
	else
		if (y > DY)
			cout << "NO\n";
		else
			cout << "SO\n";
		
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (true)
	{
		cin >> N;
		
		if (N == 0)
			return 0;

		cin >> DX >> DY;

		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			
			printResult();
		}
	}

	return 0;
}