/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:13:49 by evgen             #+#    #+#             */
/*   Updated: 2021/03/31 20:37:31 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Write a programe which:
//		- ask your name
//		- ask your age
//		- ask your address
// Then this programe display:
//		- your name
//		- your age
//		- your address

#include <iostream>
# define NM "your name:"
# define AGE "your age:"
# define ADR "your contry:"
# define MAX 20

using namespace std;

int			main(void)
{
	char	name[MAX];
	int		age;
	char	adr[MAX];

	cout << "Please, enter " << NM << "\n";
	cin >> name;
	cout << "Now ente " << AGE << "\n";
	cin >> age;
	cout << "And in last enter " << ADR << "\n";
	cin >> adr;

	cout << NM << "--> " << name << "\n";
	cout << AGE << "--> " << age << "\n";
	cout << ADR << "--> " << adr << "\n";
	return (0);
}
