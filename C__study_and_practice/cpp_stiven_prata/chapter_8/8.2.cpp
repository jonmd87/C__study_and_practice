/*
** a structure "CadyBar" includes three elements:
** 	- first element is a name of cady, type char[]
**	- second element is a weight of cady, type double
**	- third element is a quantity of calories, type int
**
** write a program that uses a function that get arguments
**  1) a referens of structure CadyBar
**  2) a ponter type char
**  3) a variable type double
**  4) a variable type int
** last three arguments must have this value:
**		char* = "Millenium Munch"
**		double = 2.85
**		int = 350
** the program has to have a function than display содержимое of structure 
** CadyBar, and this function get one argument, a reference of structure.
*/


#include <iostream>
#include <cstring>

const int 		LEN = 80;
const char 		*NAME = "Millenium Munch";
const double	WEIGHT = 2.85;
const int		CALORIES = 350;

typedef struct 		s_CadyBar {
	char*			name;
	double			weight;
	int				calor;
}					t_CadyBar;

void			init(t_CadyBar &cady, char *str, double wght, int clrs);
void			show(t_CadyBar &cady);

int				main(void)
{
	t_CadyBar		cady;

	init(cady, (char*)NAME, WEIGHT, CALORIES);
	show(cady);
	delete[] cady.name;
	return (0);
}

void			init(t_CadyBar &cady, char *str, double wght, int clrs)
{
	if (!str)
		return ;
	cady.name = new char [strlen(str) +1 ];
	strncpy(cady.name, str, strlen(str));
	cady.weight = wght;
	cady.calor = clrs;
}

void			show(const t_CadyBar &cady)
{
	std::cout << "    Name: " << cady.name << std::endl;
	std::cout << "  weight: " << cady.weight << std::endl;
	std::cout << "calories: " << cady.calor << std::endl;
}
