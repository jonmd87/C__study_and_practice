/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.4.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:22:32 by evgen             #+#    #+#             */
/*   Updated: 2021/06/01 16:22:34 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>

using namespace			std;

int						get_answer(int *num)
{
	char				ch;

	ch = 0;
	if (!(cin >> *num))
	{
		cin.clear();
		cin >> ch;
		cin.ignore(INT_MAX, '\n');
		if (tolower(ch) == 'q')
			return (1);
		cout << "only positive numbers! or q for exit" << endl;
	}
	return (0);
}

size_t						factorial(size_t num)
{
	long					res;
	
	res = 1;
	if (num > 1)
		res *= factorial(num -1);
	return (res * num);
}

int						main(void)
{
	int 					num;
	
	num = 0;
	cout << "enter number(or [q] for exit):" << endl;
	while ((get_answer(&num)) == 0)
	{
		if (num > 0)
		{
			cout << "entered number " << num << endl;
			cout << num << "! = " << factorial((size_t)num) << endl;
		}
		cout << "enter new number(or [q] for exit):" << endl;
		num = 0;
	}
	cout << "Goodbye!!!" << endl;
	return (0);
}
