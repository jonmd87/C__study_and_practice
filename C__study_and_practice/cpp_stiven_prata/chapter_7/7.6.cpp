#include <iostream>
#include <cstring>
#include <climits>

using namespace				std;

const int						LEN = 30;
const char                         *message = "enter class size(only positive numbers, or [q] for quit):";
const char					*mess_posit_num = "only p9sitive numbers, or [q] for quit:";

typedef struct					s_student {
	char						name[LEN];
	char 						hoby[LEN];
	int							oopLevel;
}								t_student;

int 							get_number (const char *message);
int								get_str(char *str);
int 							get_info(t_student st[], int n);
void							display1(t_student st);
void							display2(const t_student *st);
void							display3(const t_student st[], int n);

int							main(void)
{
	int							size;
	int 						entered;
	t_student					*std;
	
	cout << message << endl;
	size = get_number(message);
	if (size > 0)
	{
		std = new t_student [size];
		if (std)
		{
			entered = get_info(std, size);
			for (int i = 0; i < entered; i++)
			{
				display1(std[i]);
				display2(&std[i]);
			}
			display3(std, entered);
		}
	}
	delete [] std;
	cout << "GoodBye" << endl;
	return (0);
}

int							get_number(const char *message)
{
	int						num;
	char					ch;

	num = 0;
	ch = 0;
	while (!(cin >> num) || num < 1)
	{
		if (cin.fail() == true)
		{
			cin.clear();
			ch = cin.get();
			if (tolower(ch) == 'q')
				return (0);
		}
		cout << message << endl;
		cin.ignore(INT_MAX, '\n');
	}
	cin.ignore(INT_MAX, '\n');
	return (num);
}

int 							get_info(t_student std[], int n)
{
	int							entered;

	entered = 0;
	while (entered < n)
	{
		cout << "enter full name of " << entered + 1 << " student:" << endl;
		if (get_str(std[entered].name) > 0)
			return (entered);
		cout << "now enter hobby of student " << std[entered].name << endl;
		if (get_str(std[entered].hoby) > 0)
			return (entered);
		cout << "And in last enter level of OOP" << endl;
		if ((std[entered].oopLevel = get_number(mess_posit_num)) == 0)
			return (entered);
		entered++;
		cout << "OK, lets get data of another person" << endl;
	}
	return (entered);
}

int								get_str(char *str)
{
	cin.getline(str, LEN);
	if (*str == '\0')
		return (1);
	return (0);
}

void							display1(t_student st)
{
	cout << "display1:\n";
	cout << "   Name:		" << st.name << endl;
	cout << "  Hobby:		" << st.hoby << endl;
	cout << "OOP lvl:		" << st.oopLevel << endl << endl;	
}
void							display2(const t_student *st)
{
	cout << "\tdisplay2:\n";
	cout << "\t   Name:		" << st->name << endl;
	cout << "\t  Hobby:		" << st->hoby << endl;
	cout << "\tOOP lvl:		" << st->oopLevel << endl << endl;	
}
void							display3(const t_student st[], int n)
{
	int 						ind;
	
	ind = 0;
	while (ind < n)
	{
		cout << "display3:\n";
		cout << "   Name:		" << st[ind].name << endl;
		cout << "  Hobby:		" << st[ind].hoby << endl;
		cout << "OOP lvl:		" << st[ind].oopLevel << endl << endl;
		ind++;
	}
}
;
