#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;

#define MAX_RC 200

char type;
int R, C;
string line;
char bitmap[MAX_RC + 1][MAX_RC + 1];



string composite(int Y, int X, int R, int C)
{
	char t = bitmap[Y][X];
	bool isSame = true;

	for (int y = Y; y < Y+R; y++)
	{
		for (int x = X; x < X+C; x++)
		{
			if (bitmap[y][x] != t)
			{
				isSame = false;
				break;
			}
		}
	}

	if (isSame)
		return string(1,t);
	
	string tl = composite(Y, X, (R + 1) / 2, (C + 1) / 2);
	string tr = C / 2 ? composite(Y, X + (C + 1) / 2, (R + 1) / 2, C / 2) : "";
	string bl = R / 2 ? composite(Y + (R + 1) / 2, X, R / 2, (C + 1) / 2) : "";
	string br = (R / 2)*(C / 2) ? composite(Y + (R + 1) / 2, X + (C + 1) / 2, R / 2, C / 2) : "";
	string ret = "D" + tl + tr + bl + br;
	return ret;
}

int decomposite(int index, int Y, int X, int R, int C)
{
	if (line[index] != 'D')
	{
		for (int y = Y; y < Y + R; y++)
		{
			for (int x = X; x < X + C; x++)
			{
				bitmap[y][x] = line[index];
			}
		}

		return 1;
	}

	int tl = decomposite(index + 1, Y, X, (R + 1) / 2, (C + 1) / 2);
	
	int tr = 0;
	if(C/2)
		decomposite(index + 1 + tl, Y, X + (C + 1) / 2, (R + 1) / 2, C / 2);
	
	int bl = 0;
	if (R / 2)
		bl = decomposite(index + 1 + tl + tr, Y + (R + 1) / 2, X, R / 2, (C + 1) / 2);
	
	int br = 0;
	if ((C / 2)*(R / 2))
		br = decomposite(index + 1 + tl + tr + bl, Y + (R + 1) / 2, X + (C + 1) / 2, R / 2, C / 2);

	return index + 1 + tl + tr + bl + br;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	while (true)
	{
		cin >> type;

		if (type == '#')
			break;

		cin >> R >> C;

		cout << (type == 'B' ? "D" : "B")
			<< right << setw(4) << R
			<< right << setw(4) << C
			<< '\n';


		if (type == 'B')
		{
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					cin >> bitmap[r][c];
				}
			}
			
			int cnt = 0;
			
			string s = composite(0, 0, R, C);
			
			for (int i = 0; i < s.size(); i++)
			{
				cout << s[i];
				if (++cnt % 50 == 0)
					cout << '\n';
			}
			if (cnt % 50)
				cout << '\n';

		}
		else
		{
			cin >> line;

			decomposite(0, 0,0,R,C);

			int cnt = 0;

			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					cout <<  bitmap[r][c];
					
					if (++cnt % 50 == 0)
						cout << '\n';
				}
			}
			if(cnt % 50)
				cout << '\n';
		}

	}

	return 0;
}

