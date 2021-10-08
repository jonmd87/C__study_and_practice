/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.1.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:09:30 by evgen             #+#    #+#             */
/*   Updated: 2021/07/28 20:30:37 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Define the class that present the bank account
**		- the class must have name of person
**		- the number of bank account 
**		- balance
**
** the functions elements must do this things:
**		- craft and initialize the object
**		- set of first values
**		- show name of person, number of bank account, balance
**		- adding founds
**		- withdraw founds
** Then you should write a short program 
** that imagine this class and show how works functions in this class
** 
*/


#include <iostream>
#include <cstring>

class Bank_acc
{
private:
	static const int	LEN = 50;
	char				person[LEN];
	char				acc_num[LEN];
	double				money;
	void				clean_arr(char *str);
public:
	Bank_acc(); //default constructor -->line 50
	Bank_acc(const char *name, const char *acc_n, double m);//constructor -->line 57
	~Bank_acc();// -->line 64
	void	adding(const double add);// -->line 69
	void	withdraw(const double withdraw);// -->line 74
	void	show(void);// -->line 79
	void	change_person(const char *src);
	void	change_acc_num(const char *src);
};

void					Bank_acc::clean_arr(char *str)
{
	int					ind;

	ind = 0;
	while (ind < LEN)
		str[ind++] = '\0';
}

Bank_acc::Bank_acc()
{
	strcpy(person, "EMPTY");
	strcpy(acc_num, "EMPTY");
	money = 0;
}

Bank_acc::Bank_acc(const char *name, const char *acc_n, double m)
{
	strncpy(person, name, strlen(name) + 1);
	strncpy(acc_num, acc_n, strlen(acc_n) + 1);
	money = m;
}

Bank_acc::~Bank_acc()
{
	std::cout << "GoodBye" << std::endl;
}

void	Bank_acc::adding(const double add)
{
	money += add;
}

void	Bank_acc::withdraw(const double withdraw)
{
	money -= withdraw;
}

void					Bank_acc::show(void)
{
	std::cout << "person         : " << person << std::endl;
	std::cout << "account number : " << acc_num << std::endl;
	std::cout << "money          : " << money << std::endl;
}

void					Bank_acc::change_person(const char *src)
{
	int					len;

	if (src)
		len = strlen(src);
	if (len > LEN)
		len = len;
	clean_arr(person);
	strncpy(person, src, len); 
}

void					Bank_acc::change_acc_num(const char *src)
{
	int					len;

	if (src)
		len = strlen(src);
	if (len > LEN)
		len = len;
	clean_arr(acc_num);
	strncpy(acc_num, src, len); 
}

int						main(void)
{
	Bank_acc			evgen = Bank_acc("Evgenii Gerasimenko", "E_G_7891/60/70", 1000);
	std::cout << std::endl;
	evgen.show();
	evgen.change_person("AAAAAAAAAAAAAAAA");
	evgen.adding(200);
	std::cout << std::endl;
	evgen.show();
	evgen.withdraw(1000);
	evgen.change_acc_num("A_A_000000/00/00/");
	std::cout << std::endl;
	evgen.show();
	return (0);
}
