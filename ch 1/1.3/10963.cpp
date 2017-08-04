#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>


using namespace std;

int N,A,B;

int main(int argc, char** argv)
{
	int tc,T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> T;
	for (tc = 1; tc < T+1; tc++)
	{
		cin >> N >> A >> B;
		int gap = A - B;
		int i = 1;
		for (; i < N; i++)
		{
			cin >> A >> B;
			if (A - B != gap)
				gap = -1;
		}
		
		if (gap != -1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		
		if (tc < T)
			cout << endl;
	}

	return 0;
}