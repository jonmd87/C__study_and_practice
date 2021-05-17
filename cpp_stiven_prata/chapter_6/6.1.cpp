#include <iostream>
#include <cctype>

using namespace 	std;
const unsigned char	MIN = 64;
const unsigned char	MAX = 91;
const unsigned char	min = 96;
const unsigned char max = 123;

int				main(void)
{
	unsigned char	ch;
	
	ch = 0;
	cout << "This program will repeat all entered characters, ";
	cout << "numbers will be ignored" << endl;
	ch = cin.get();
	while (ch != '@')
	{
		if ((isprint(ch) && (!isdigit(ch))) || isspace(ch))
		{
			if (ch > MIN && ch < MAX)
				cout << (unsigned char)tolower(ch);
			else if (ch < 123 && ch > 96)
				cout << (unsigned char)toupper(ch);
			else
				cout.put(ch);
		}
		ch = cin.get();
	}
	cout << "\nWas entered charachter [" << ch << "]" << endl;
	cout << "GoodBye" << endl;
	return (0);
}
