/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:58:53 by evgen             #+#    #+#             */
/*   Updated: 2021/04/20 21:28:53 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write the programe that ask your:
// 	- height in foots and inches
//	- weight in pounds
// then programe display your BODY MASS INDEX (BMI)
// to calculate the BMI need to convert foots in inches
// then height in inched convert in metrs
// pounds need to convert in killograms
// formulf BMI = mass in kill / (height in metrs * height in metrs)

#include <iostream>
#include <cmath>
using namespace std;

const double metr_inch = 0.0254;
const double kg_pounds = 2.2;

double			bmi(double metrs, double kg);
double			metrs(const double foot, const double inch);
double 			kg(const double pounds);


int				main(void)
{
	int			foot;
	int			inch;
	int			pound;

	cout << "Enter your height\nFirst enter foots:_____\b\b\b\b\b";
	cin >> foot;
	cout << "\nNow enter inches:_____\b\b\b\b\b";
	cin >> inch;
	cout << "\nAnd in last enter your weight in pounds:_____\b\b\b\b\b";
	cin >> pound;
	cout << "\n";
	cout << "Your BODY MASS INDEX is [";
	cout << bmi(metrs((double)foot, inch), kg((double)pound));
	cout << "]\n";
	cout << "\n";
	cout << "Good bye!!!\n";
	return (0);
}

double			metrs(const double foot, const double inch)
{
	double		metrs;
	
	metrs = foot * 12 + inch;
	metrs *= metr_inch;
	return (metrs);
}

double 			kg(const double pounds)
{
	return (pounds / kg_pounds);
}

double			bmi(double metrs, double kg)
{
	return (kg / (metrs * metrs));
}
