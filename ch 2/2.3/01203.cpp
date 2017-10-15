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

#define MAX_INST 1000

int N;
string inst;
int n_inst;

struct Instruction
{
	int num;
	int p, v;

	bool operator < (const Instruction& is) const
	{
		if (v != is.v)
			return v > is.v;
		return num > is.num;
	}
};

int main(int argc, char** argv)
{	
	//std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	priority_queue<Instruction> pq;
	
	while (true)
	{
		cin >> inst;
		if (inst[0] == '#')
			break;
		Instruction is;
		cin >> is.num >> is.p;
		is.v = is.p;
		pq.push(is);
	}

	cin >> N;

	while (N--)
	{
		Instruction is = pq.top();
		pq.pop();
		cout << is.num << '\n';
		is.v += is.p;
		pq.push(is);
	}

	
	return 0;
}