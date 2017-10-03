#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define MAX_NSQ 100

int N, S, Q;



int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	
	for (int i = 0; i < tc; i++)
	{
		cin >> N >> S >> Q;
		stack<int> carrierStack;
		queue<int> stationQueue[MAX_NSQ];


		for (int n = 0; n < N; n++)
		{
			int Qi;
			cin >> Qi;

			for (int qi = 0; qi < Qi; qi++)
			{
				int a;
				cin >> a;
				stationQueue[n].push(a - 1);
			}
		}
		
		int cur = 0, time = 0;

		while (true)
		{
			while (!carrierStack.empty()
				&& (carrierStack.top() == cur || stationQueue[cur].size() < Q))
			{
				if (carrierStack.top() != cur)
					stationQueue[cur].push(carrierStack.top());
				carrierStack.pop();
				time++;
			}

			while (carrierStack.size() < S && !stationQueue[cur].empty())
			{
				carrierStack.push(stationQueue[cur].front());
				stationQueue[cur].pop();
				time++;
			}

			bool isClear = carrierStack.empty();
			
			for (int q = 0; q < N; q++)
				isClear &= stationQueue[q].empty();

			if (isClear)
				break;

			time += 2;
			cur = (cur + 1) % N;
		}
		cout << time << '\n';
	}
	
	return 0;
}