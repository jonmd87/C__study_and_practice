/*
** write a function that, 
** if one argument is set, address of string, function print this string
** if second argument 
** is set and argument has type of int and it's more than zero
** function prints string, as much times as function was called
** pay attention, that second argument doesn't mean how much will be printed
** the sring.
** use this function in program that show how it works
*/

#include <iostream>
const char		*str = "hello Johny!!!";

void				print_str(const char *str, int i = 1);

int						main(void)
{
	int					num;
	
	num = 0;
	std::cout << "enter a number\n";
	std::cin >> num;
	print_str(str, num);
	print_str(str, 20);
	print_str(str);
	print_str(str);
	print_str(str);
	print_str(str);
	print_str(str,2);
	return (0);
}

void				print_str(const char *str, int i)
{
	static int	quan = 1;
	if (i < 2)
		i = 1;
	else
		i = quan;
	while (i-- > 0)
		std::cout << i + 1 << ")\t" << str << std::endl;
	quan++;
	using namespace std;
	cout << endl;
}
