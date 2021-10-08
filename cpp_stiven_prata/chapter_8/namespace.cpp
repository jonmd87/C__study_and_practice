#include <iostream>

namespace my{  
	double a;
	double b;
	int	  c;
	};
double a = 1;	
int				main(void)
{
	std::cout << "enter val:\n";
	std::cin >> ::a;  // read in global spacename
	std::cout << "my a = " << my::a << std::endl;
	std::cout << "a = " << ::a << std::endl;
	using namespace my;
	double a =10.2;
	std::cout << "my a = " << a << std::endl;
	return (0);
}
