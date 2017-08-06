#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int N, A, B;
string line;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 0;

	while (cin >> line)
	{
		tc++;
		
		cin >> N;
		cout << "Case " << tc << ":\n";

		for (int i = 0; i < N; i++)
		{
			cin >> A >> B;

			if (A > B)
			{
				int t = B;
				B = A;
				A = t;
			}

			int first = line[A];

			for (int j = A + 1; j <= B; j++)
			{
				if (first != line[j])
				{
					first = -1;
					break;
				}
			}

			if (first == -1)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
		
	}
	return 0;
}