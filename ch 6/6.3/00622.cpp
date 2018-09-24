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

using namespace std;

#define EXPRESSION 0
#define COMPONENT 1
#define FACTOR 2
#define NUM 3

string line;
int result;
int i;

extern bool isExpression();
extern bool isComponent();
extern bool isFactor();

bool isExpression()
{
	if (i == line.length())
		return true;
	else if (i > line.length())
		return false;

	int ret;

	if (!isComponent())
	{
		return false;
	}

	ret = result;

	while (i < line.length() && line[i] == '+')
	{
		i++;
		if (isExpression())
		{
			result += ret;
			return true;
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool isComponent()
{
	if (i >= line.length())
		return false;
	
	int ret;

	if (!isFactor())
	{
		return false;
	}

	ret = result;

	if (i < line.length() && line[i] == '*')
	{
		i++;
		if (isComponent())
		{
			result *= ret;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}

bool isFactor()
{
	if (i >= line.length())
		return false;

	int ret=0;

	if ('0' <= line[i] && line[i] <= '9')
	{
		while ('0' <= line[i] && line[i] <= '9')
		{
			ret = ret * 10 + line[i++] - '0';
		}

		result = ret;

		return true;
	}
	else if (line[i] == '(')
	{
		i++;
		if (isExpression() && i < line.length() && line[i++] == ')')
		{
			return true;
		}
	}
	
	return false;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif


	int T;
	cin >> T;
	while (T--)
	{
		cin >> line;
		i = 0;
		if (isExpression() && i == line.length())
			cout << result << '\n';
		else
			cout << "ERROR\n";
	}

	return 0;
}
