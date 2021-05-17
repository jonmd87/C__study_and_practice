#include <iostream>
#include <cstring>
using namespace std;

typedef struct			s_car {
	char				*name;
	unsigned int		year;
}					t_car;

t_car				**init_arr_struct(const int quan)
{
	t_car			**cars;
	
	
	cars = NULL;
	cars = new t_car*[quan];
	cout << "1address of cars[" << cars << "]\n";
	return (cars);
}

char 				*get_name(int num)
{
	int 				len;
	char				*temp;
	char 			*name;
	
	len = 100;
	temp = new char[len + 1];
	memset(temp, '\0', len);
	cout << "Enter name of " << num << " car\n";
	cin.get();
	cin.getline(temp, 100);
	name = new char[strlen(temp) + 1];
	strncpy(name, temp, strlen(temp) + 1);
	delete[] temp;
	return (name);
}

void					get_data(t_car **cars, int max)
{
	int				ind;
	
	ind = 0;
	while (ind < max)
	{
		cars[ind] = new t_car;
		cars[ind]->name = get_name(ind + 1);
		cout << "Enter year of manufacture:\n";
		cin >> cars[ind]->year;
		ind++;
	}
	cout << "OK, data was get\n";
}

void					show_data(t_car **cars, int quan)
{
	int				ind;
	
	ind = 0;
	cout << "\nCars:\n";
	while (ind < quan)
	{
		cout << "\tMarka:		" << cars[ind]->name << '\n';
		cout << "\tYear: 		" << cars[ind]->year << "\n\n";
		ind++;
	}
}

void					del_data(t_car **cars, int max)
{
	int				ind;
	
	ind = 0;
	while (ind < max)
	{
		delete[] cars[ind]->name;
		cout << "ind =" << ind << "\n";
		ind++;
	}
	delete[] *cars;
	cout << "3address of cars[" << *cars << "]\n";
}

int 					main(void)
{
	t_car			**cars;
	int				quan;
	
	quan = 0;
	cout	<< "Enter quantity of cars:\n";
	cin >> quan;
	cars = init_arr_struct(quan);
	get_data(cars, quan);
	show_data(cars, quan);
	del_data(cars, quan);
	if (!cars)
		cout << "array of pointers(t_car*) cleaned\n";
	show_data(cars, quan);
	return (0);
}
