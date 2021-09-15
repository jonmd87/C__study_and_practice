#include <iostream>
#include <cstring>
using namespace std;

const unsigned int LEN = 3;
const unsigned int MAX = 20;
const char NM[LEN][MAX] = {"Mars", "Snickers", "Bounty"};
const char *NS = "\n";

typedef struct 		t_cady_bar {
	char				name[MAX];
	double 			weight;
	unsigned int 		kal;
}					s_cady_bar;

void					init_snacks(s_cady_bar *snack, size_t len)
{
	unsigned int		ind;
	unsigned int		kal;
	double 			weight;
	
	ind = 0;
	kal = 100;
	weight = 8.0;
	while (ind++ != len)
	{
		strncpy(snack->name, NM[ind -1], MAX);
		snack->weight = weight + (double)ind;
		snack->kal = kal + ind;
		snack++;
	
	}
}

void					show_data(s_cady_bar *snack, size_t len)
{
	unsigned int		ind;
	
	ind = 0;
	while (ind++ != len)
	{
		cout << "Name of snack:   " << snack->name << NS;
		cout << "       weight:   " << snack->weight << NS;
		cout << "     kalories:   " << snack->kal << NS;
		cout << NS;
		snack++;
	}
}

int					main(void)
{
	s_cady_bar		snacks[LEN];
	init_snacks(snacks, LEN);
	show_data(snacks, LEN);
	return (0);
}
