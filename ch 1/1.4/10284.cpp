#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

#define LEN 8

char board[LEN][LEN];
char line[200];

//                     r     c
map<char, vector<pair<int, int> > > m;

int main(int argc, char** argv)
{

	//black lower case : 0 -> LEN
	//white upper case : LEN -> 0

	//p,r,n,b,q,k
	m['p'] = { {1,-1}, {1,1} };
	m['P'] = { { -1,-1 },{ -1,1 } };

	m['R'] = m['r'] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
	

	m['N'] = m['n'] = { {1, -2}, {2, -1}, {2, 1}, {1, 2}
			,{ -1, -2 },{ -2, -1 },{ -2, 1 },{ -1, 2 } };
	
	m['B'] = m['b'] = { {-1,-1}, {-1,1}, {1,-1}, {1,1} };

	m['K'] = m['k'] = m['Q'] = m['q'] = { { -1,-1 },{ -1,1 },{ 1,-1 },{ 1,1 },{ -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

	while (cin >> line)
	{
		int r = 0;
		int c = 0;

		for (int r = 0; r < LEN; r++)
			for (int c = 0; c < LEN; c++)
				board[r][c] = '.';

		for (int i = 0; line[i]; i++)
		{
			if ('0' <= line[i] && line[i] <= '9')
				c += line[i] - '0';
			else if (line[i] == '/')
				r++, c = 0;
			else
				board[r][c] = line[i], c++;
		}

		for (int r = 0; r < LEN; r++)
		{
			for (int c = 0; c < LEN; c++)
			{
				if (board[r][c] == '.' || board[r][c] == ',')
					continue;

				if (board[r][c] == 'p' || board[r][c] == 'P'
					|| board[r][c] == 'k' || board[r][c] == 'K'
					|| board[r][c] == 'n' || board[r][c] == 'N')
				{
					for (int i = 0; i < m[board[r][c]].size(); i++)
					{
						int nextR = r + m[board[r][c]][i].first;
						int nextC = c + m[board[r][c]][i].second;

						if (nextR < 0 || nextR >= LEN || nextC < 0 || nextC >= LEN)
							continue;
						
						if (board[nextR][nextC] == '.')
							board[nextR][nextC] = ',';
					}
				}
				else
				{
					for (int i = 0; i < m[board[r][c]].size(); i++)
					{
						for (int i = 0; i < m[board[r][c]].size(); i++)
						{
							int nextR = r + m[board[r][c]][i].first;
							int nextC = c + m[board[r][c]][i].second;

							while (0 <= nextR && nextR < LEN && 0 <= nextC && nextC < LEN)
							{
								if (board[nextR][nextC] == '.')
									board[nextR][nextC] = ',';

								if (board[nextR][nextC] != ',')
									break;

								nextR += m[board[r][c]][i].first;
								nextC += m[board[r][c]][i].second;
							}
						}
					}
				}
			}
		}

		int cnt = 0;

		for (int r = 0; r < LEN; r++)
		{
			for (int c = 0; c < LEN; c++)
			{
				if (board[r][c] == '.')
					cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;

}