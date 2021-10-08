#include <iostream>
using namespace std;

const unsigned int		LEN = 20;
const char *ERR_ALLOC = "Can't allocate memory for struct.name\n";
const char *NS = "\n";

typedef struct		t_pizza {
	char				*name;
	unsigned int 		diametr;
	unsigned int		weight;
}					s_pizza;

s_pizza				*get_data(void)
{
	s_pizza 			*pizza;
	
	pizza = (s_pizza*)calloc(sizeof(s_pizza), 1);
	pizza->name = (char*)calloc(sizeof(char), LEN + 1);
	if (!pizza->name)
	{
		cout << ERR_ALLOC;
		exit(2);
	}
	cout << "Please, enter the manufacture:" << NS;
	cin.getline(pizza->name, LEN);
	cout << " Now enter diametr:" << NS;
	cin >> pizza->diametr;
	cout << "In the last, enter weight" << NS;
	cin >> pizza->weight;
	return (pizza);
}

void					show_data(s_pizza *pizza)
{
	cout << "Name:    " << pizza->name << NS;
	cout << "diam:    " << pizza->diametr << NS;
	cout << "weig:    " << pizza->weight << NS;
}

int					main(void)
{
	s_pizza 			*pizza;
	
	pizza = get_data();
	show_data(pizza);
	return (0);
}
