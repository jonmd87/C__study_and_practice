/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.4.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:53:41 by evgen             #+#    #+#             */
/*   Updated: 2021/04/07 22:02:20 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

static int		cel_far(const int cel)
{
	return ((int)((double)cel * 1.8 + 32)); 
}

int				main(void)
{
	int			cel;

	cel = 0;
	cout << "Please enter a cellsius value:\n";
	cin >> cel;
	cout << cel << " = " << cel_far(cel) << "\n";
	return (0);
}
