#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

#define LEN 8

string board[LEN];

//                     r     c
map<char, vector<pair<int, int> > > m;

int main(int argc, char** argv)
{
	int TC = 1;

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


	while (true)
	{
		bool isEmpty = true;

		for (int i = 0; i < LEN; i++)
		{
			cin >> board[i];
			if (board[i] != "........")
				isEmpty = false;
		}

		if (isEmpty)
			break;

		bool hasAnswer = false;
		char opponent;

		for (int r = 0; r < LEN && !hasAnswer; r++)
		{
			for (int c = 0; c < LEN && !hasAnswer; c++)
			{
				if (board[r][c] == '.')
					continue;

				opponent = board[r][c] > 'a' ? 'K' : 'k';

				if (board[r][c] == 'p' || board[r][c] == 'P' 
					|| board[r][c] == 'k' || board[r][c] == 'K'
					|| board[r][c] == 'n' || board[r][c] == 'N')
				{
					for (int i = 0; i < m[board[r][c]].size() && !hasAnswer; i++)
					{
						int nextR = r + m[board[r][c]][i].first;
						int nextC = c + m[board[r][c]][i].second;

						if (nextR < 0 || nextR >= LEN || nextC < 0 || nextC >= LEN)
							continue;
						if (board[nextR][nextC] == opponent)
						{
							hasAnswer = true;
							break;
						}
					}
				}
				else
				{
					for (int i = 0; i < m[board[r][c]].size() && !hasAnswer; i++)
					{
						for (int i = 0; i < m[board[r][c]].size() && !hasAnswer; i++)
						{
							int nextR = r + m[board[r][c]][i].first;
							int nextC = c + m[board[r][c]][i].second;

							while (0 <= nextR && nextR < LEN && 0 <= nextC && nextC < LEN && !hasAnswer)
							{
								if (board[nextR][nextC] == opponent)
								{
									hasAnswer = true;
									break;
								}

								if (board[nextR][nextC] != '.')
									break;

								nextR += m[board[r][c]][i].first;
								nextC += m[board[r][c]][i].second;
							}
						}
					}
				}

			}
		}


		cout << "Game " << '#' << TC++ << ": ";

		if (hasAnswer)
			cout << (opponent == 'k' ? "black" : "white");
		else
			cout << "no";
		cout << " king is in check.\n";

	}
	

	return 0;

}