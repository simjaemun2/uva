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

struct Expr{
	char oper;
	string exp;
};

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;
		
		map<string, Expr> mEXPR;

		string answer;

		for (int i = 0; i < N; i++)
		{
			string var, exp1, oper, exp2, result;
			cin >> var >> exp1 >> exp1 >> oper >> exp2;

			Expr expr;
			expr.oper = oper[0];

			if (expr.oper == '+')
			{
				if (mEXPR.find(exp1) != mEXPR.end())
				{
					result += mEXPR[exp1].exp;
				}
				else//num
				{
					result += exp1;
				}

				result += expr.oper;

				if (mEXPR.find(exp2) != mEXPR.end())
				{
					if (mEXPR[exp2].oper == '+')
						result += '(' + mEXPR[exp2].exp + ')';
					else
						result += mEXPR[exp2].exp;
				}
				else
				{
					result += exp2;
				}
			}
			else// '*'
			{
				if (mEXPR.find(exp1) != mEXPR.end())
				{
					if(mEXPR[exp1].oper == '+')
						result += '(' + mEXPR[exp1].exp + ')';
					else
						result += mEXPR[exp1].exp;
				}
				else
				{
					result += exp1;
				}

				result += expr.oper;

				if (mEXPR.find(exp2) != mEXPR.end())
				{
					result += '(' + mEXPR[exp2].exp + ')';
				}
				else
				{
					result += exp2;
				}
			}

			expr.exp = result;
			mEXPR[var] = expr;
			answer = result;
		}

		cout << "Expression #" << tc << ": " << answer << '\n';
	}
	

	return 0;
}
