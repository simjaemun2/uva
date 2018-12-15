#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int N, R;

struct Node {
	int base;
	int size;
	int d;
	vector<pair<int, int> > bound;
};

int main(int argc, char** argv)
{
	cin >> N >> R;
	
	string line;

	map<string, Node> m;

	getline(cin, line);

	for (int n = 0; n < N; n++)
	{
		getline(cin, line);

		string name;
		istringstream iss(line);
		
		Node node;

		iss >> name >> node.base >> node.size >> node.d;

		for (int d = 0; d < node.d; d++)
		{
			int l,u;
			iss >> l >> u;
			node.bound.push_back({ l,u });
		}

		m[name] = node;
	}

	for (int r = 0; r < R; r++)
	{
		getline(cin, line);

		string name;
		istringstream iss(line);

		iss >> name;
		
		Node& node = m[name];

		int sum = node.base;

		cout << name << '[';

		for (int d = 0; d < node.d; d++)
		{
			int i;
			iss >> i;
			cout << i;
			if (d < node.d - 1)
				cout << ", ";

			int t = node.size;

			for (int dd = d + 1; dd < node.d; dd++)
			{
				t *= (node.bound[dd].second - node.bound[dd].first + 1);
			}

			sum += t * (i - node.bound[d].first);
		}

		cout << "] = " << sum << '\n';
	}
	

	return 0;

}