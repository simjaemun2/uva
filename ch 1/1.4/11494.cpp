#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int srcr, srcc, desr, desc;
	
	while (cin >> srcr >> srcc >> desr >> desc, srcr+ srcc + desr + desc)
	{
		if (srcr == desr && srcc == desc)
		{
			cout << "0\n";
			continue;
		}

		int dr = abs(desr - srcr);
		int dc = abs(desc - srcc);

		if (dr == 0 || dc == 0 || dr == dc)
			cout << "1\n";
		else
			cout << "2\n";
	}
	

	return 0;

}