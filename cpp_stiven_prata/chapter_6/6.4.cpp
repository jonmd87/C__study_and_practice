/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.4.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:43:58 by evgen             #+#    #+#             */
/*   Updated: 2021/05/19 20:54:11 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

using namespace			std;

typedef struct				s_bop {
	char					*name;
	char					*post;
	char					*nick;
	size_t					preference;
}						t_bop;

void						menu(void)
{
	cout << "a) display by name" << endl;
	cout << "b) display by title" << endl;
	cout << "c) display by nickname" << endl;
	cout << "d) display by preference" << endl;
	cout << "q) quit" << endl;
}

t_bop 					**init_arr(size_t quan)
{
	t_bop				**temp;
	
	if (!(temp = new t_bop*[quan + 1]))
	{
		cout << "Can't to allocate memory for t_bop" << endl;
		exit(2);
	}
	temp[quan] = nullptr;
	return (temp);
}

char						*get_string(const char *title, size_t num)
{
	char					*temp;
	char					*str;
	size_t					len;

	temp = new char[100] ();
	cout << "Enter " << title << " for " << num << " person" << endl;
	cin >> temp;
	if ((len = strlen(temp)) > 0)
		str = new char[len + 1];
	strncpy(str, temp, len + 1);
	delete[] temp;
	temp = nullptr;
	return (str);
}

void						fill_struct(t_bop **people, size_t max)
{
	size_t					ind;

	ind = 0;
	while (ind < max)
	{
		people[ind] = new t_bop;
		people[ind]->name = get_string("name", ind + 1);
		people[ind]->post = get_string("post", ind + 1);
		people[ind]->nick = get_string("nick", ind + 1);
		cout << "Enter preference (integer)" << endl;
		cin >> people[ind]->preference;
		cin.get();
		ind++;
	}
}

unsigned char				get_answer(void)
{
	char					ch;
	
	ch = 'k';
	cout << "Choose the letter:" << endl;
	while (1)
	{
		if (strchr("abcdq", ch))
			break;
		menu();
		cout << "Only these letters [a,b,c,d,q]" << endl;
		cin >> ch;
		cin.get();
	}
	return ((unsigned char)ch);
}

int					show_data(t_bop **people, unsigned char answer, size_t max)
{
	switch (answer)
	{
		case 'a':
			cout << "By name:" << endl;
			for (size_t i = 0; i < max; i++)
				cout << people[i]->name << endl;
			break ;
		case 'b':
			cout << "By title:" << endl;
			for (size_t i = 0; i < max; i++)
				cout << people[i]->post << endl;
			break ;
		case 'c':
			cout << "By nickname:" << endl;
			for (size_t i = 0; i < max; i++)
				cout << people[i]->nick << endl;
			break ;
		case 'd':
			cout << "By preference:" << endl;
			for (size_t i = 0; i < max; i++)
				cout << people[i]->preference << endl;
			break ;
		case 'q':
			cout << "QUIT:" << endl;
			return (1);
		default :
			cout << "unnown answer" << endl;
			break ;
	}
	return (0);
}

void					clean_mem(t_bop **people, size_t max)
{
	size_t				ind;

	ind = 0;
	while (ind < max)
	{
		delete people[ind]->name;
		people[ind]->name = nullptr;
		delete people[ind]->post;
		people[ind]->post = nullptr;
		delete people[ind]->nick;
		people[ind]->nick = nullptr;
	}
	delete[] people;
	people = nullptr;
}

int						main(void)
{
	t_bop 				**people;
	unsigned char		answer;
	size_t				quan;
	
	quan = 1;
	people = init_arr(quan);
	fill_struct(people, quan);
	answer = get_answer();
	while ((show_data(people, answer, quan)) == 0)
		answer = get_answer();
	clean_mem(people, quan);
	people = nullptr;
	cout << "Goodbye" << endl;
	return (0);
}
