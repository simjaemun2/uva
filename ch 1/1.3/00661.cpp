#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <map>

using namespace std;
#define MX_N 20
int N, M, C;
int cp[MX_N + 1];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 0;

	while (true)
	{
		cin >> N >> M >> C;
		if (N + M + C == 0)
			break;

		tc++;

		for (int i = 1; i <= N; i++)
		{
			cin >> cp[i];
			cp[i] *= -1;
		}

		int cur = 0;
		int index;
		int mxCp = 0;
		
		for (int i = 0; i < M; i++)
		{
			cin >> index;
			cp[index] *= -1;
			cur += cp[index];
			
			if (mxCp < cur)
				mxCp = cur;
		}

		cout << "Sequence " << tc << '\n';
		if (mxCp > C)
			cout << "Fuse was blown.\n\n";
		else
		{
			cout << "Fuse was not blown.\n";
			cout << "Maximal power consumption was " << mxCp << " amperes.\n\n";
		}

	}
	return 0;
}