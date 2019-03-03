#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;
#define MAX_K 100
int K, M, C, R;
string course;


int main(int argc, char** argv)
{
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	while (true)
	{
		cin >> K;
		if (K == 0)
			return 0;

		set<string> courses;

		cin >> M;

		for (int i = 0; i < K; i++)
		{
			cin >> course;
			courses.insert(course);
		}
			
		bool result = true;

		for (int i = 0; i < M; i++)
		{
			cin >> C >> R;
			int sum = 0;

			for (int j = 0; j < C; j++)
			{
				cin >> course;
				if (courses.find(course) != courses.end())
					sum++;
			}

			if (sum < R)
				result = false;
		}

		if (result)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	
	return 0;
}