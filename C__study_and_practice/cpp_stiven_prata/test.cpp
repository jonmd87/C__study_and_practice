/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:03:42 by evgen             #+#    #+#             */
/*   Updated: 2021/05/21 22:16:09 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

using namespace 		std;

void					picture_line(char *str, int min, int max)
{
	for (int i = 0; i < 6; i++)
	{
		
	}
}

int						main(void)
{
	int					len;
	char				*str;

	len = 66;
	str = new char[len + 1];
	if (!str)
		exit(2);
	str[0] = '|';
	str[len - 2] = '|';
	picture_line(str, 0, len - 2);
	delete str;
	return (0);
}
