#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <math.h>

using namespace std;

string line;

int idx;

double getResult(stringstream& ss)
{
	double result;

	while (ss && ss.peek() == ' ')
		ss.get();

	if (ss.peek() != '(')
		ss >> result;
	else
	{
		ss.get();
		
		double p, e1, e2;
		ss >> p;
		e1 = getResult(ss);
		e2 = getResult(ss);
		while (ss && ss.get() != ')');
		result = p*(e1 + e2) + (1 - p)*(e1 - e2);
	}

	return result;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (getline(cin, line))
	{
		if (line == "()")
			break;
		stringstream ss(line);
		
		double result = getResult(ss);
		result = round(result * 100) / 100;
		
		printf("%.2f\n", result);
	}

	return 0;
}
