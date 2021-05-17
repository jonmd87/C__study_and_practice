/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.5.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:15:29 by evgen             #+#    #+#             */
/*   Updated: 2021/05/17 21:01:30 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

const unsigned int	M = 12;
const unsigned int	Y = 3;
const unsigned char ns = '\n';
const char			*months[M] = {"January", "February", "March", "April",
									"May", "June", "July", "August",
									"September", "October", "November",
												"December"};
void					get_data(int *arr, int max)
{
	int					ind;

	ind = 0;
	if (max <= ind)
		return ;
	while (ind < max)
	{
		cout << "Enter quantity of saled books in " << months[ind] << ns;
		cin >> arr[ind];
		ind++;
	}
}

double					average(int *arr, int year, int month)
{
	double				average[Y];
	double				ave;

	for (int i = 0; i < year; i++)
	{
		for (int y = 0; y < month; y++)
			average[i] += *(arr + (i * month) + y);
		average[i] /= month;
	}
	for (int x = 0; x < year; ave += average[x], x++)
		cout << "average of " << x + 1 << " year = " <<  average[x] << endl;
	return (ave / year);
}

int						main(void)
{
	int					quantity[Y][M];
	unsigned int		years;
	double				aver;

	years = 0;
	while (years < Y)
	{
		cout << "\nEnter data of " << years + 1 << " year" << ns;
		get_data(&quantity[years][0], M);
		years++;
	}
	aver = average(&quantity[0][0], Y, M);
	cout << "average of all time = " << aver << endl;
	return (0);
}
