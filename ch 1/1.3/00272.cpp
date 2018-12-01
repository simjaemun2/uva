#include <iostream>
#include <string>

using namespace std;

#define abs(x) ((x) < 0 ? -(x) : x)

#define MAX_N 10000
#define MOD 1000000007

int N, X;

char line[1000];

int main(int argc, char** argv)
{
	char c;

	bool first = true;

	while (cin.getline(line, 1000))
	{
		
		for (int i = 0; line[i]; i++)
		{
			if (line[i] == '\"')
			{
				cout << (first ? "``" : "''");
				first = !first;
			}
			else
				cout << line[i];
		}

		cout << '\n';
	}
	

	return 0;

}