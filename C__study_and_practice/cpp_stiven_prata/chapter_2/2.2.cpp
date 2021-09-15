/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.2.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:01:45 by evgen             #+#    #+#             */
/*   Updated: 2021/04/08 20:57:42 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

# define INCH 2.54
# define FOOT INCH * 12
# define POUNDS 2.2046

static void		convert(int h)
{
	double		foot;
	double		inch;
	
	foot = (int)((double)h / (FOOT));
	inch = (h - ((double)foot * inch)) / INCH;
	cout << "[" << foot << "]foots and [" << inch << "]inch\n";
}

int				main(void)
{
	int			weight;
	int			height;

	cout << "Enter your height:\n";
	cin >> height;
	cout << "Now enter your weidht:\n";
	cin >> weight;
	cout << "Your parametrs:\n";
	cout << "\theight[" << height << "]cm\n";
	cout << "\tweight[" << weight << "]kg\n";
	convert(height);
	cout << "\tweight[" << (double)weight / POUNDS << "]pounds\n";
	return (0);
}
