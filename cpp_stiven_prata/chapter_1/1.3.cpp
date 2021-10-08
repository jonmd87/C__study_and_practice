/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.3.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:44:58 by evgen             #+#    #+#             */
/*   Updated: 2021/04/07 21:52:08 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

static void		first_fun(void)
{
	cout << "Three blind mice\n" << "Three blind mice\n";
}

static void		second_fun(void)
{
	cout << "see how they run\n" << "see how they run\n";
}

int				main(void)
{
	first_fun();
	second_fun();
	return (0);
}
