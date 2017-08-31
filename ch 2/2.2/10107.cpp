#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	vector<long long int> v;
	int N;

	while (cin >> N)
	{
		v.push_back(N);
		nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
		int n1 = v[v.size() / 2];
		if(v.size() % 2)
			cout << n1 << '\n';
		else
		{
			nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());
			int n2 = v[v.size() / 2 - 1];
			cout << (n1 + n2) / 2 << '\n';
		}
	}



	return 0;
}