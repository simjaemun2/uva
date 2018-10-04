#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <map>

using namespace std;

#define MAX_N 100
#define MAX_D 4

int N;

vector<vector<char> > adj;
map<char, bool> visited;
vector<char> i2char;

bool dfs(vector<char>& answer)
{
	if (answer.size() == i2char.size())
	{
		cout << answer[0];
		for (int i = 1; i < answer.size(); i++)
		{
			cout << ' ' << answer[i];
		}

		cout << '\n';

		return true;
	}

	bool ret = false;

	for (auto c: i2char)
	{
		if (!visited[c])
		{
			for (auto nextC : adj[c])
			{
				if (visited[nextC])
					return false;
			}

			visited[c] = true;
			answer.push_back(c);
			
			ret |= dfs(answer);

			answer.pop_back();
			visited[c] = false;
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	cin >> N;
	cin.ignore(100, '\n');
	string line;

	for(int tc=0; tc<N; tc++)
	{
		if(tc)
			cout << '\n';
		adj.clear();
		visited.clear();
		i2char.clear();

		getline(cin, line);
		getline(cin, line);
		istringstream iss = istringstream(line);
		char a, b, c;

		while (iss >> a)
		{
			i2char.push_back(a);
		}

		sort(i2char.begin(), i2char.end());

		getline(cin, line);
		iss = istringstream(line);

		adj.resize(100);

		while (iss >> a >> b >> c)
		{
			adj[a].push_back(c);
		}
		
		vector<char> answer;

		if (!dfs(answer))
			cout << "NO\n";

		//
	}
	
	
	return 0;
}
