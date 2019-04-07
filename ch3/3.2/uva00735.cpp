#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>

#include <memory.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <utility>
#include <sstream>
#include <functional>
#include <map>
#include <limits.h>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;

int N;

int permutations[4] = { 1,1,3,6 };

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	int tc = 1;
	set<int> s;
	
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			s.insert(i*j);
		}
	}
	
	vector<int> score(s.begin(), s.end());
	score.push_back(50);
	sort(score.begin(), score.end());

	const int LEN = score.size();

	while (cin >> N, N > 0)
	{
		int combi = 0;
		int perm = 0;

		for (int i = 0; i < LEN; i++)
		{
			int s1 = score[i];
			int p1 = 3;


			for (int j = i; j < LEN; j++)
			{
				int s2 = s1 + score[j];

				int p2 = p1;

				if (score[i] == score[j])
				{
					p2--;
				}

				for (int k = j; k < LEN; k++)
				{
					int s3 = s2 + score[k];
					int p3 = p2;
					if (score[i] == score[k])
					{
						p3--;
					}

					if (score[j] == score[k])
					{
						p3--;
					}
			
					if (s3 == N)
					{
						combi++;
						perm += permutations[p3];
					}
				}
			}
		}

		if (combi)
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << N << " IS " << combi << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << N << " IS " << perm << ".\n";
		}
		else
		{
			cout << "THE SCORE OF " << N << " CANNOT BE MADE WITH THREE DARTS.\n";
		}

		cout << "**********************************************************************\n";
	}
	
	cout << "END OF OUTPUT\n";

	return 0;
}

