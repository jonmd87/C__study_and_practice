/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.3.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:07:31 by evgen             #+#    #+#             */
/*   Updated: 2021/08/02 20:17:57 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Look at next structure:
**		|----------------------------------------------|
**		|											   |
** 		|	typedef struct	s_cust {				   |
**		|		char 		fullname[35];			   |
**		|		double		payment;				   |
**		|	}			t_cust; // cust == customer	   |
**		|----------------------------------------------|
**
** You have to write a program that:
** 		- is adding an element in stack
**		- is delete an element from stack
** stack is described in a class, craft this class.
** Each customer must have own payment, when the program delete 
** an element from stack, the paymen of this elemen are adding to
** common sume, and current summ must be show.
*/

#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>

const int 		LEN = 30;
const int		MAX = 10;

typedef struct	s_cust {
	char 		*fullname;
	double		payment;
	}			t_cust; // cust == customer

class Stack
{
	static const int 	SZ = 10;
	t_cust 				customers[SZ];
	double				all_sum;
	void				clean_arr(char *str);
public:
	Stack();
	~Stack();
	int		adding(void);
	void	deleting(void);
	void	show(void);
};
	
int 					main(void)
{
	int					ind;

	ind = 0;
	Stack  				my_stack;
	my_stack.show();
	while (ind < MAX)
	{	
		std::cout << "Enter datum of " << ind + 1 << " person" << std::endl;
		if (my_stack.adding() == 1)
			break ;
		ind++;
	}
	my_stack.show();
	while (ind != 0)
	{	
		
		my_stack.deleting();
		my_stack.show();
		ind--;
	}
	return (0);
}

Stack::Stack()
{
	int			ind;
	
	ind = 0;
	while (ind < SZ)
	{
		if ((customers[ind].fullname = new char [LEN]))
		{
			clean_arr(customers[ind].fullname);
			customers[ind].payment = 0;
		}
		else
		{
			std::cout << "Can't allocate memory for customers[";
			std::cout << ind << "]" << std::endl;
			exit(1);
		}
		ind++;
	}
	customers[SZ].fullname = nullptr;
	all_sum = 0;
}

Stack::~Stack()
{
	int			ind;

	ind = 0;
	while (ind < SZ)
		delete customers[ind++].fullname;
	std::cout << "Goodbye" << std::endl;
}

void				Stack::clean_arr(char *str)
{
	int 			ind;
	
	ind = 0;
	while (ind < LEN)
		*(str + ind++) = '\0';
}

int					Stack::adding(void)
{
	int				ind;

	ind = 0;
	while (customers[ind].fullname[0] != '\0')
		ind++;
	std::cout << "enter name of customer:" << std::endl;
	std::cin.getline(customers[ind].fullname, LEN - 1, '\n');
	std::cin.putback('\n');
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	if (customers[ind].fullname[0] == '\0')
		return (1);
	std::cout << "enter payment of customer:" << std::endl;
	std::cin >> customers[ind].payment;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	return (0);
}

void	Stack::deleting(void)
{
	int			last;

	for (last = 0; last < SZ && customers[last].fullname[0] != '\0'; last++);
	if (last > 0)
		last -= 1;
	std::cout << "\t\t\tdeleted[" << customers[last].fullname << "(";
	std::cout << customers[last].payment << ")]" << std::endl;
	all_sum += customers[last].payment;
	clean_arr(customers[last].fullname);
	customers[last].payment = 0;
}

void	Stack::show(void)
{
	int			ind;

	ind = 0;
	while (customers[ind].fullname != nullptr && customers[ind].fullname[0] != '\0')
	{
		std::cout << "Name     :" << customers[ind].fullname << std::endl;
		std::cout << "Payment  :" << customers[ind].payment << std::endl;
		std::cout << "-------------------------------" << std::endl;
		ind++;
	}
	std::cout << "\tamount sume :  " << all_sum << std::endl;
}
