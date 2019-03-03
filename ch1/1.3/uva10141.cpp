#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int N, P;

int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc = 0;

	cin >> N >> P;

	while (true)
	{
		tc++;
		

		
		string req;
		
		for (int i = 0; i < N; i++)
		{
			cin.ignore();
			getline(cin, req);
		}
			

		double minD = 0;
		double maxR = 0;
		string result, name;
		double d;
		int r;

		for (int j = 0; j < P; j++)
		{
			//cin.ignore();
			getline(cin, name);
			scanf("%lf %d\n", &d, &r);

			for (int i = 0; i < r; i++)
			{
				getline(cin, req);
			}
				

			if (r > maxR || r == maxR && d < minD)
			{
				result = name;
				maxR = r;
				minD = d;
			}
		}

		cout << "RFP #" << tc << '\n' << result << '\n';
		cin >> N >> P;
		if (N + P == 0)
			break;
		cout << '\n';
	}
	return 0;
}