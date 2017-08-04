#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>


using namespace std;

int F, A, B, C;

int main(int argc, char** argv)
{
	int tc,T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		int result = 0;
		cin >> F;
		for (int i = 0; i < F; i++)
		{
			cin >> A >> B >> C;
			result += A*C;
		}
		cout << result << '\n';
			
		
	}

	return 0;
}