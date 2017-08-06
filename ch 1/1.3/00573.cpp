#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <map>

using namespace std;
double H, U, D, F;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	while (true)
	{
		cin >> H >> U >> D >> F;
		if (H == 0)
			break;
		double cur = 0.0;
		F = U * F / 100.0;
		int day = 0;

		while (true)
		{
			day++;
			cur += U;
			if(U > 0)
				U -= F;
			if (cur > H)
				break;
			cur -= D;
			if (cur < 0)
				break;
		}
		if (cur < 0.0)
			cout << "failure";
		else
			cout << "success";
		cout << " on day " << day << '\n';
		
	}
	return 0;
}