#include <iostream>
using namespace std;

const unsigned int		M = 80;

typedef struct			t_Cady_Bar {
	char 			manufact[M];
	double			weight;
	unsigned int		kal;
}					s_Cady_Bar;

void					show_data(s_Cady_Bar data)
{
	cout << "Name of manufactur:   " << data.manufact << "\n";
	cout << "            weight:   " << data.weight << "\n";
	cout << "   calorie content:   " << data.kal << "\n";
}

int					main(void)
{
	s_Cady_Bar		snack = {"Moch Munch", 9.08, 20};
	show_data(snack);
	cout << "good buy\n";
	return (0);
}