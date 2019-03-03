#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <map>

using namespace std;
#define MAX_N 10
int N;
string names[MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	
	cin >> N;
	while (true)
	{
		map<string, int> m;
		for (int i = 0; i < N; i++)
		{
			cin >> names[i];
		}

		for (int i = 0; i < N; i++)
		{
			string name;
			int spent, numberOfSpent;
			cin >> name >> spent >> numberOfSpent;

			if(numberOfSpent != 0)
				m[name] -= spent / numberOfSpent * numberOfSpent;

			for (int j = 0; j < numberOfSpent; j++)
			{
				cin >> name;
				m[name] += spent / numberOfSpent;
			}
		}

		for (int i = 0; i < N; i++)
			cout << names[i] << ' ' << m[names[i]] << '\n';
		
		if (cin >> N)
			cout << '\n';
		else
			break;
	}
	return 0;
}