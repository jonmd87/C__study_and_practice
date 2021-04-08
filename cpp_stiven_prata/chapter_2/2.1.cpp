/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:04:04 by evgen             #+#    #+#             */
/*   Updated: 2021/04/08 20:01:14 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

# define INCH 2.54
# define FOOT (INCH * 12)

int				main(void)
{
	double		height;
	double		rest;

	height = 0;
	cout << "Please enter your height, in cm\n";
	cin >> height;
	cout << "Your height:\n";
	cout << "\t_cm_[" << height << "]\n";
	cout << "\tinch[" << height / INCH << "]\n";
	rest = ((int)(height / FOOT) * INCH) / INCH;
	cout << "\tfoot[" << (int)(height / FOOT) << "] and inch[" << rest << "]\n";
	return (0);
}
