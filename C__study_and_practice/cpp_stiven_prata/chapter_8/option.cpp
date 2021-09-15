#include <iostream>

void 		show_str(char *str = "my dear ")
{
	std::cout << str << std::endl;
}

int			main(void)
{
	char		*str = "my favorite ";
	show_str(str);
	show_str();
	return (0);
}