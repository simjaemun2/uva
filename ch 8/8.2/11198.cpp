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
#include <math.h>
#include <functional>

using namespace std;

#define INF 987654321

#define MAX_N 8

bool isPrime[16] = {
	false, false, true, true, false
	,true, false, true, false, false,
	false, true, false, true, false, false
};


int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	
	int tc = 1;

	vector<int > input(8);

	while (cin >> input[0], input[0])
	{
		for (int i = 1; i < MAX_N; i++)
			cin >> input[i];

		set<vector<int> > s;
		s.insert(input);

		queue<pair<int, vector<int> > > q;
		q.push({ 0, input });

		int answer = -1;

		while (!q.empty())
		{
			int step = q.front().first;
			vector<int > v = q.front().second;
			q.pop();

			int i;
			
			for (i = 1; i < MAX_N && abs(v[i]) - abs(v[i - 1]) == 1; i++);
			
			if (i == MAX_N)
			{
				answer = step;
				break;
			}

			for (i = 0; i < MAX_N - 1; i++)
			{
				int ai = abs(v[i]);

				for (int j = i + 1; j < MAX_N; j++)
				{
					int aj = abs(v[j]);

					if ((v[i] ^ v[j]) < 0 && isPrime[ai + aj])
					{
						vector<vector<int> > nv(4);

						for (int k = 0; k < i; k++)
						{
							nv[0].push_back(v[k]);
							nv[1].push_back(v[k]);
						}
							
						nv[0].push_back(v[j]);
						nv[1].push_back(v[i]);

						nv[0].push_back(v[i]);
						nv[1].push_back(v[j]);
						
						for (int k = i + 1; k < MAX_N; k++)
						{
							if (k != j)
							{
								nv[0].push_back(v[k]);
								nv[1].push_back(v[k]);
							}
						}

						for (int k = 0; k < j; k++)
						{
							if (k != i)
							{
								nv[2].push_back(v[k]);
								nv[3].push_back(v[k]);
							}
						}

						nv[2].push_back(v[j]);
						nv[3].push_back(v[i]);

						nv[2].push_back(v[i]);
						nv[3].push_back(v[j]);

						for (int k = j + 1; k < MAX_N; k++)
						{	
							nv[2].push_back(v[k]);
							nv[3].push_back(v[k]);	
						}

						for (int k = 0; k < 4; k++)
						{
							if (s.find(nv[k]) == s.end())
							{
								s.insert(nv[k]);
								q.push({ step + 1, nv[k] });
							}
						}
					}
				}
			}
		}

		cout << "Case " << tc++ << ": " << answer << '\n';
	}

	
	return 0;
}