#include <iostream>

using 		namespace std;

int	num = 3;

void			show_duplicate(void);

int			main(void)
{
	cout << "in main num = " << num << endl;
	show_duplicate();
	return (0);
}

void			show_duplicate(void)
{
	int		num;
	
	num = 5;
	cout << "in show num = " << num << endl;
	cout << "but global = " << ::num << endl;
}