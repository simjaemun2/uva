#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;
#define MAX_BEND 100000
int N;
string bend;


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	map<string, int> dir;
	dir["-y"] = 0;
	dir["+y"] = 1;
	dir["-z"] = 2;
	dir["+z"] = 3;
	dir["-x"] = 4;
	dir["+x"] = 5;
	dir["No"] = 6;
	
	string dirr[] = {
		"-y","+y","-z","+z","-x","+x"
		//0    1    2    3    4    5
	};

	while (true)
	{
		cin >> N;
		if (N == 0)
			return 0;

		int cur = 5;

		for (int i = 0; i < N - 1; i++)
		{
			cin >> bend;
			int d = dir[bend];
			if (d == 6)
				continue;
			else if (d == 0)//-y
			{
				if (cur == 5)//+x -> -y
					cur = 0;
				else if (cur == 4)//-x -> +y
					cur = 1;
				else if (cur == 0)//-y -> -x
					cur = 4;
				else if (cur == 1)//+y -> +x
					cur = 5;
			}
			else if (d == 1)//+y
			{
				if (cur == 5)//+x -> +y
					cur = 1;
				else if (cur == 4)//-x -> -y
					cur = 0;
				else if (cur == 1)//+y -> -x
					cur = 4;
				else if (cur == 0)//-y -> +x
					cur = 5;
			}
			else if (d == 2)//-z
			{
				if (cur == 5)//+x -> -z
					cur = 2;
				else if (cur == 4)//-x -> +z
					cur = 3;
				else if (cur == 2)//-z -> -x
					cur = 4;
				else if (cur == 3)//+z -> +x
					cur = 5;
			}
			else if (d == 3)//+z
			{
				if (cur == 5)//+x -> +z
					cur = 3;
				else if (cur == 4)//-x -> -z
					cur = 2;
				else if (cur == 3)//-z -> -x
					cur = 4;
				else if (cur == 2)//+z -> +x
					cur = 5;
			}
		}
		
		cout << dirr[cur] << '\n';
	}

	
	return 0;
}