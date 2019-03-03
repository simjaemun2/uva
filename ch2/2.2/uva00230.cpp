#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string, string> info;

bool compare(string& a, string& b)
{
	if (info[a] == info[b])
		return a < b;

	return info[a] < info[b];
}

int main(int argc, char** argv)
{
	string line;
	vector<string> books;
	vector<string> shelve;
	
	while (getline(cin, line), line != "END")
	{
		stringstream ss(line);
		string book, token, author;
	
		ss >> book;
		
		while (ss >> token)
		{
			if (token == "by")
				break;
			book += ' ' + token;
		}

		ss >> author;
		while (ss >> token)
			author += ' ' + token;
		
		books.push_back(book);

		info[book] = author;
	}

	sort(books.begin(), books.end(), compare);

	while (getline(cin, line), line != "END")
	{
		stringstream ss(line);
		string inst, book, token;
		
		ss >> inst;

		if (inst == "BORROW")
		{
			ss >> book;
			
			while (ss >> token)
				book += ' ' + token;

			for (auto it = shelve.begin(); it != shelve.end(); it++)
			{
				if (*it == book)
				{
					shelve.erase(it);
					break;
				}
			}

			for (auto it = books.begin(); it != books.end(); it++)
			{
				if (*it == book)
				{
					books.erase(it);
					break;
				}
			}
		}
		else if (inst == "RETURN")
		{
			ss >> book;
			
			while (ss >> token)
				book += ' ' + token;

			shelve.push_back(book);
		}
		else// SHELVE
		{
			sort(shelve.begin(), shelve.end(), compare);

			for (string book : shelve)
			{
				auto it = books.begin();
				auto beforeit = it;

				for (; it != books.end(); it++)
				{
					if (compare(book, *it))
						break;
					beforeit = it;
				}

				if (it == books.begin())
				{
					cout << "Put " << book << " first\n";
				}
				else
				{
					cout << "Put " << book << " after " << *beforeit << '\n';
				}

				books.insert(it, book);
			}

			shelve.clear();
			cout << "END\n";
		}
	}
	
	

	return 0;

}