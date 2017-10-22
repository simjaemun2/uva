#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

int N;

int main(int argc, char** argv)
{	
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (cin >> N)
	{
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		bool isPQ = true, isS = true, isQ = true;

		for (int i = 0; i < N; i++)
		{
			int inst, elmt;
			cin >> inst >> elmt;
			
			if (inst == 1)
			{
				if(isPQ)
					pq.push(elmt);
				if(isS)
					s.push(elmt);
				if(isQ)
					q.push(elmt);
			}
			else//inst == 2
			{
				if (isPQ)
				{
					if ((pq.empty() || pq.top() != elmt))
						isPQ = false;
					else
						pq.pop();
				}
				if (isQ)
				{
					if ((q.empty() || q.front() != elmt))
						isQ = false;
					else
						q.pop();
				}
				if (isS)
				{
					if ((s.empty() || s.top() != elmt))
						isS = false;
					else
						s.pop();
				}
			}
		}

		if (isPQ && !isS && !isQ)
			cout << "priority queue\n";
		else if (!isPQ && isS && !isQ)
			cout << "stack\n";
		else if (!isPQ && !isS && isQ)
			cout << "queue\n";
		else if (!isPQ && !isS && !isQ)
			cout << "impossible\n";
		else
			cout << "not sure\n";

	}
	return 0;
}