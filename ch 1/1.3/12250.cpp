#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <map>


using namespace std;

 string input;

int main(int argc, char** argv)
{
	int tc;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	map<string, string> m;
	
	/*
	English word ¡°HELLO¡±. For
example in Spanish the word equivalent to ¡°HELLO¡±
is ¡°HOLA¡±. In German, French, Italian and Russian
language the word that means (or similar to)
¡°HELLO¡± is ¡°HALLO¡±, ¡°BONJOUR¡±, ¡°CIAO¡± and
¡°ZDRAVSTVUJTE¡±
	
	*/
	m.insert(map<string, string>::value_type("HELLO", "ENGLISH"));
	m.insert(map<string, string>::value_type("HOLA", "SPANISH"));
	m.insert(map<string, string>::value_type("HALLO", "GERMAN"));
	m.insert(map<string, string>::value_type("BONJOUR", "FRENCH"));
	m.insert(map<string, string>::value_type("CIAO", "ITALIAN"));
	m.insert(map<string, string>::value_type("ZDRAVSTVUJTE", "RUSSIAN"));


	for (tc = 1; true; tc++)
	{
		cin >> input;

		if (input == "#")
			return 0;
		
		map<string, string>::iterator it = m.find(input);

		cout << "Case " << tc << ": ";

		if (it == m.end())
			cout << "UNKNOWN\n";
		else
			cout << it->second << '\n';
	}

	return 0;
}