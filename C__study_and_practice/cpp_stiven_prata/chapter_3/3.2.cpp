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

const double cm_inch = 0.0254;
const double kg_pouds = 2.2;

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
//	bmi(convert_height_in_metrs(foot, inch), convert_weight_in_kg(pounds));
	cout << foot;
	cout << "\n";
	cout << inch;
	cout << "\n";
	cout << pound;
	cout << "\n";
	cout << "Good bye!!!\n";
	return (0);
}
