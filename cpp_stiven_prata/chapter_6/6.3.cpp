// write a program that display a menu
// menu consist of four items
// the user can chose only pemised letters
// if user entered other letter, program will show menu
// and ask to enter right letter.

#include <iostream>
using namespace		 std;

const unsigned int		M = 6;
char					arr[M][15] = {"america", "bolivia", "canada", "denmark",
							"menu", "quit"};
const char 			*br1 = "<<";
const char			*br2 = ">>";

void					menu(void)
{
	cout << "you must enter only these letters:" << endl;
	cout << "[a] [b] [c] [d] [m] [q]" << endl;
}

void 				show_answer(const char ch)
{
	switch  (ch)
	{
		case 'a':
			cout << br1 << arr[0] << br2 << endl;
			break;
		case 'b':
			cout << br1 << arr[1] << br2 << endl;
			break;
		case 'c':
			cout << br1 << arr[2] << br2 << endl;
			break;
		case 'd':
			cout << br1 << arr[3] << br2 << endl;
			break;
		case 'm':
			cout << br1 << arr[4] << br2 << endl;
			menu();
			break;
	}
}


int					 main(void)
{
	unsigned char		ch;
	
	while (1)
	{
		cout << "please enter the letter\n";
		ch = cin.get();
		cin.get();
		ch = tolower(ch);
		if (strchr("abcdm", ch))
			show_answer(ch);
		else if (ch == 'q')
			break;
		else
			cout << "wrong answer, try again" << endl;
	}
	cout << "Goodbye!!!" << endl;
	return (0);
}