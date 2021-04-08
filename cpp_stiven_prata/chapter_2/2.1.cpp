/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:04:04 by evgen             #+#    #+#             */
/*   Updated: 2021/04/08 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

# define INCH 2.54
# define FOOT (INCH * 12)

int				main(void)
{
	double		height;

	height = 0;
	cout << "Please enter your height, in cm\n";
	cin >> height;
	cout << "Your height:\n";
	cout << "\t_cm_[" << height << "]\n";
	cout << "\tinch[" << height / INCH << "]\n";
	cout << "\tfoot[" << (int)(height / FOOT) << "]\n";
	return (0);
}
