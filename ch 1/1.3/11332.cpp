#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

int A;

int main(int argc, char** argv)
{
	int tc,T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	//cin >> T;
	while (true)
	{
		cin >> A;

		if (A == 0)
			return 0;

		while (true)
		{
			if (A < 10)
			{
				cout << A << endl;
				break;
			}
			
			int R = A%10;

			while (A > 0)
			{
				A /= 10;
				R += A % 10;
			}

			A = R;
		}
	}

	return 0;
}