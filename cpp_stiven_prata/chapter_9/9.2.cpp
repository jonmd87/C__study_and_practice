/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.2.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgen <jonmd87@live.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:05:42 by evgen             #+#    #+#             */
/*   Updated: 2021/08/02 17:06:38 by evgen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** the class:
** 
** class Golf
** {
** private:
** 		static const int LEN = 40;
** 		char fullname[LEN];
**		int	 handicap;
**		void	clean_arr(char *dst);
	
** public:
** Golf();
** Golf(const char *str, int hc);
** void change_fullname(const char *str);
** void change_handicap(int hc);
** void showgolf(const t_golf &g);
** ~Golf();
**}
** 	compil some files with this header file, first file must have descriptions 
** of functions that are in header file.
** second file must contain main function, in main function you have to releze
** all 	functions that are prototiped in header file.
** for example:
** you declare an array of struct t_golf, then you realeze loop that gets data
** for each structure in array, if was entered empty string taking data is stoped
** then your program must show all geted data.
*/

#include <iostream>
#include <cstring>


class Golf
{
	static const int	LEN = 40;
	char				fullname[LEN];
	int					handicap;
	void				clean_arr(char *dst);
public:

Golf();
Golf(const char *str, int hc);
~Golf();
void 		change_fullname(const char *str);
void		change_handicap(int hc);
void 		show(void);
};	

Golf::Golf()
{
	clean_arr(fullname);
	strncpy(fullname, "empty", strlen("empty") + 1);
	handicap = 0;
}

Golf::Golf(const char *str, int hc)
{
	int			len;
	
	len = strlen(str);
	if (len > LEN)
		len = LEN - 1;
	clean_arr(fullname);
	strncpy(fullname, str, len + 1);
	handicap = hc;
}

Golf::~Golf()
{
	std::cout << "Goodbye" << std::endl;
}

void				Golf::clean_arr(char *dst)
{
	int				ind;
	
	ind = 0;
	while (ind < LEN)
		dst[ind++] = '\0';
}
void 				Golf::change_fullname(const char *str)
{
	int			len;
	
	len = strlen(str);
	if (len > LEN)
		len = LEN - 1;
	clean_arr(fullname);
	strncpy(fullname, str, len + 1);
}

void				Golf::change_handicap(int hc)
{
	handicap = hc;
}

void 				Golf::show(void)
{
	std::cout << "Name     :" << fullname << std::endl;
	std::cout << "handicap :" << handicap << std::endl;
}

int								main(void)
{
	Golf						first;
	Golf 	second = Golf("my_game", 123);
	first.show();
	second.show();
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout<< std::endl;
	first.change_fullname("Johny Babalu");
	first.change_handicap(278);
	first.show();
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout<< std::endl;
	second = first;
	std::cout<< "first:" << std::endl;
	first.show();
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout<< std::endl;
	std::cout<< "second:" << std::endl;
	second.show();
	return (0);
}
