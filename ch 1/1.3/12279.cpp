#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

int N,A,result;

int main(int argc, char** argv)
{
	int tc;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	for (tc = 1; true; tc++)
	{
		cin >> N;

		if (N == 0)
			return 0;
		result = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> A;
			if (A > 0)
				result += 1;
			else
				result -= 1;
		}

		cout << "Case " << tc << ": " << result << '\n';

	}

	return 0;
}