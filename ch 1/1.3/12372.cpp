#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>



using namespace std;

int L, W, H;

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
		cin >> L >> W >> H;
		
		cout << "Case " << tc << ": ";

		if (L > 20 || W > 20 || H > 20)
			cout << "bad\n";
		else
			cout << "good\n";
	}

	return 0;
}