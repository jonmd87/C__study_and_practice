#include <iostream>
using namespace std;

const unsigned int	LEN = 80;

typedef struct		s_student {
	char			first_name[LEN];
	char 		second_name[LEN];
	char 		grade;
	unsigned int	age;
}				t_student;

t_student 		*init(void)
{
	t_student 	*pers;
	pers = (t_student*)calloc(sizeof(t_student), 1);
	if (!pers)
		exit(2);
	pers->grade = 0;
	pers->age = 0;
	return (pers);
}

void				get_data(t_student *pers)
{
	cout << "Please, enter your name:\n";
	cin.getline(pers->first_name, LEN);
	cout << "What is your second name?\n";
	cin.getline(pers->second_name, LEN);
	cout << "Ok, what letter grade do you deserve?\n";
	cin >> pers->grade;
	cout << "What is your age?\n";
	cin >> pers->age;
}

void				show_data(t_student *pers)
{
	cout << pers->first_name << ", ";
	cout << pers->second_name << "\n";
	cout << pers->grade << "\n";
	cout << pers->age << "\n";
}

int				main(void)
{
	t_student		*pers;
	
	pers = NULL;
	pers = init();
	get_data(pers);
	show_data(pers);
	return (0);
}
