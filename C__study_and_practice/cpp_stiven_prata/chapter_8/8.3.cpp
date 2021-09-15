/*
** below are presented a body of program, you must write functions and prototips
** take a note that in program will be two functions <<show>>
** each of this functions must use argumets by defolt.
** use CONST where you deceded to neseccery
** take a notice that function <<set>> must use operatore NEW for allocation of 
** memory
*/

#include <iostream>
#include <cstring>

typedef struct					s_str {
	char						*str;
	int							ct;
}								t_str;

void							set(t_str &beany, const char *orign);
void							show(const t_str &beany, int max = 1);
void							show(const char *str, int max = 1);

int								main(void)
{
	t_str						beany;
	char						testing[] = "Realty isn't what it used to be";
	set(beany, testing);
	show(beany);
	std::cout << "------------------" << std::endl;
	show(beany, 10);
	std::cout << "------------------" << std::endl;
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	std::cout << "------------------" << std::endl;
	show(testing,3);
	std::cout << "------------------" << std::endl;
	show("done");
	return (0);
}

void							set(t_str &beany, const char *orign)
{
	if (!orign)
		return ;
	beany.ct = strlen(orign);
	beany.str = new char[beany.ct + 1];
	strncpy(beany.str, orign, beany.ct);
}

void							show(const t_str &beany, int max)
{
	int 						i;
	
	i = 0;
	while (i++ < max)
		std::cout << "str -> \"" << beany.str << "\"" << std::endl;
}

void							show(const char *str, int max)
{
	int 						i;
	
	i = 0;
	while (i++ < max)
		std::cout << "str -> \"" << str << "\"" << std::endl;
}
