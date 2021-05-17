#include <iostream>
using namespace std;

typedef struct			s_piz {
	char				*name;
	unsigned int		diametr;
	unsigned int 		weight;
}					t_piz;

void					get_data(t_piz *piz)
{
	piz->name = new char[20];
	cout << "enter diametr of pizza:\n";
	cin >> piz->diametr;
	cin.get();
	cout << "enter name of manufacture:\n";
	cin.getline(piz->name, 20);
	cout << "enter weight of pizza:\n";
	cin >> piz->weight;
}

void					show_data(t_piz *piz)
{
	char				ns = '\n';
	cout << "manufacture:		" << piz->name << ns;
	cout << "    diametr:		" << piz->diametr << ns;
	cout << "     weight:		" << piz->weight << ns;
}

int					main(void)
{
	t_piz			*piz;
	
	piz = new t_piz;
	get_data(piz);
	show_data(piz);
	return (0);
}