/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.2.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:24:25 by evgen             #+#    #+#             */
/*   Updated: 2021/04/07 21:37:56 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

# define FAR 220

int				main(void)
{
	int			yard;

	yard = 0;
	cout << "Enter distance in yards:\n";
	cin >> yard;
	cout << "distance in yard[" << yard << "]\n";
	cout << "distance in farlong[" << yard * FAR <<"]\n";
	return (0);
}
