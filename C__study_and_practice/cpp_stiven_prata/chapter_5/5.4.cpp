/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.4.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 00:59:52 by evgen             #+#    #+#             */
/*   Updated: 2021/05/09 17:19:27 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

const unsigned int	M = 12;
const char 			ns = '\n';
static const char	*months[M] {"January", "February", "March", "April", "May", "June",
 "July", "August", "September", "October", "November", "December"};

ssize_t			calc(unsigned int cash[], ssize_t len)
{
	ssize_t		res;
	ssize_t		ind;

	res = 0;
	ind = 0;
	if (len < 1)
		return (len);
	while (ind < len)
	{
		res += cash[ind];
		ind++;
	}
	return (res);
}

double			average(unsigned int cash[], ssize_t len)
{
	ssize_t		res;
	ssize_t		ind;

	res = 0;
	ind = 0;
	if (len < 1)
		return (len);
	while (ind < len)
	{
		res += cash[ind];
		ind++;
	}
	return ((double)res / (double)len);
}

int				main(void)
{
	unsigned int	cash[M];
	int				ind;
	
	ind = 0;
	while (ind < (int)M)
	{
		cout << "enter cash of " << months[ind] << ns;
		cin >> cash[ind];
		ind++;
	}
	cout << "revenue for the year:	" << calc(cash, M) << ns;
	cout << "      anual averange:	" << average(cash, M) << ns;	
	return (0);
}
