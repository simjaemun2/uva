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

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int L, U, R;

	vector<int> v(10);

	int tc = 1;

	while (cin >> L >> U >> R, R)
	{
		map<int, bool> visited;

		for (int r = 0; r < R; r++)
		{
			cin >> v[r];
		}

		queue<pair<int, int> > q;
		visited[L] = true;
		q.push({ L, 0 });

		int answer = -1;

		while (!q.empty())
		{
			int step = q.front().second;
			int num = q.front().first;

			q.pop();

			if (num == U)
			{
				answer = step;
				break;
			}

			for (int i=0; i<R; i++)
			{
				int pressed = (num + v[i]) % 10000;


				if (!visited[pressed])
				{
					visited[pressed] = true;
					q.push({ pressed, step + 1 });
				}
			}
		}

		cout << "Case " << tc++ << ": ";

		if (answer == -1)
			cout << "Permanently Locked\n";
		else
			cout << answer << '\n';
	}



	return 0;
}
