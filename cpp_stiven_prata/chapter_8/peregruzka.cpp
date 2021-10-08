#include <iostream>
#include <cstring>

void		show_data1(char *str);
//int 		show_data(const char *str);

int			main(void)
{
	char 		*str1 = " hello my dear";
	const char 	*str2 = "Goodbye";
	
	std::cout << "len of str " << show_data(str1) << std::endl;
	std::cout << "len of str " << show_data(str2);
}

void 		show_data1(char *str)
{
	std::cout << str << std::endl;
}

int			show_data(const char *str)
{
	std::cout << str;
	return (strlen(str));
}