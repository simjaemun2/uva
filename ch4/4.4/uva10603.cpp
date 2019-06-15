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
#include <queue>


using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int, int > PII;
typedef pair<double, double > PDD;
typedef pair<LL, LL> PLL;
typedef pair<int, PII> PPII;
typedef vector<int > VI;
typedef vector<VI > VVI;
typedef vector<PII > VPII;
typedef vector<string > VS;
typedef vector<bool > VB;
typedef vector<double > VD;
typedef vector<PII> VPII;
typedef vector<vector<PII> > VVPII;

const int INF = 987654321;
int tc, TC;

const int MAX_D = 4;
const int MAX_DIAG = 8;
int DY[] = { -1,1,0,0 , -1,-1,1,1};
int DX[] = { 0,0,-1,1 , -1,1,-1,1};

int A, B, C, D;
map<PPII, int> s;
queue<pair<int, PPII>> q;

void insertSet(int na, int nb, int nc, int ns)
{
	PPII next = { na, {nb, nc} };

	if (s.find(next) == s.end() || s[next] > ns)
	{
		s[next] = ns;
		q.push({ ns, next });
	}
}

int main(int argc, char** argv)
{
#ifdef _WIN32
	freopen("Text1.txt", "r", stdin);
#endif

	cin >> TC;
	
	for (tc = 1; tc <= TC; tc++)
	{
		cin >> A >> B >> C >> D;
		int maxD = 0;
		
		q.push({ 0, {0,{0,C}} });
		s.clear();
		s[{ 0,{0,C} }] = 0;
		int na, nb, nc, ns;

		map<int, int> m;

		while (!q.empty())
		{
			int step = q.front().first;
			int a = q.front().second.first;
			int b = q.front().second.second.first;
			int c = q.front().second.second.second;
			q.pop();

			if (m.find(a) == m.end())
			{
				m[a] = step;
			}
			else
			{
				m[a] = min(m[a], step);
			}

			if (m.find(b) == m.end())
			{
				m[b] = step;
			}
			else
			{
				m[b] = min(m[b], step);
			}

			if (m.find(c) == m.end())
			{
				m[c] = step;
			}
			else
			{
				m[c] = min(m[c], step);
			}

			if (a > 0)
			{
				if (b < B) // a -> b
				{
					if (a + b <= B)
					{
						nb = a + b;
						na = 0;
						ns = step + a;
					}
					else
					{
						nb = B;
						na = a + b - B;
						ns = step - b + B;
					}
					nc = c;

					insertSet(na, nb, nc, ns);
				}

				//a -> c

				nb = b;
				na = 0;
				nc = a + c;
				ns = step + a;

				insertSet(na, nb, nc, ns);
			}

			if (b > 0)
			{
				if (a < A) // b -> a
				{
					if (a + b <= A)
					{
						na = a + b;
						nb = 0;
						ns = step + b;
					}
					else
					{
						na = A;
						nb = a + b - A;
						ns = step - a + A;
					}
					nc = c;

					insertSet(na, nb, nc, ns);
				}

				//b -> c
				na = a;
				nb = 0;
				nc = b + c;
				ns = step + b;

				insertSet(na, nb, nc, ns);
			}

			if (a < A && c > 0)
			{
				nb = b;

				if (a + c < A)
				{
					na = a + c;
					nc = 0;
					ns = step + c;
				}
				else
				{
					na = A;
					nc = c - A + a;
					ns = step + A - a;
				}

				insertSet(na, nb, nc, ns);
			}

			if (b < B && c > 0)
			{
				na = a;

				if (b + c < B)
				{
					nb = b + c;
					nc = 0;
					ns = step + c;
				}
				else
				{
					nb = B;
					nc = c - B + b;
					ns = step + B - b;
				}

				insertSet(na, nb, nc, ns);
			}
		}

		int i = D;
		while (m.find(i) == m.end())
		{
			i--;
		}

		cout << m[i] << ' ' << i << '\n';
	}
	
	

	return 0;
}