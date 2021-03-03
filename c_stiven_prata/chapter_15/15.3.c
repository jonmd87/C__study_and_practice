/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/02/21 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write a function that takes an int object 
** and returns the number of bits included in it.i
** Test the function in a program.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

# define INT CHAR_BIT * sizeof(int)
# define MSK 0xFFFFFFFF

static int				get_num(int *num);
static char				*itobit(const int num, unsigned int cell);
static int				count_enabled_bits(const char *str);
static void				clean_mem(char *str);

int						main(void)
{
	int					num;
	char				*str;

	num = 0;
	while (get_num(&num) > 0)
	{
		str = itobit(num, (unsigned int)INT);
		printf("in number =%i= =%s= are enabled %i bits\n", 
										num, str, count_enabled_bits(str));	
		clean_mem(str);
	}	
	puts("!!!GOOD BYE!!!");
	return (0);
}

static int				get_num(int *num)
{
	unsigned char		ch;

	ch = 0;
	puts("Enter a number, or enter [q] for exit.");
	while ((scanf("%i", &(*num))) != 1)
	{
		while ((ch = getchar()) != '\n')
			if (toupper(ch) == 'Q')
				return (0);
		puts("!!!Wrong input data!!!");
		puts("Enter a number, or enter [q] for exit.");
	}
	return (1);
}

static char				*itobit(const int n, unsigned int cell)
{
	char				*str;
	int					num;

	str = NULL;
	if (n < 0)
		num = ((~n));
	else
		num = (int)n;
printf("mask[%u]\n", MSK);
printf("int) mask[%i]\n", (int)MSK + 2);
printf("num[%i]\n~n[%i]\n", num, n ^ MSK);
	if (cell > 0 && (str = (char*)calloc(sizeof(char), cell + 1)))
	{
		memset(str, '0', cell);
		while (num != 0)
		{
			str[--cell] = num % 2 + '0';
			num /= 2;
		}		
	}
	return (str);
}

static int				count_enabled_bits(const char *str)
{
	int					val;

	val = 0;
	while (*str)
	{
		if (*str == '1')
			val++;
		str++;
	}
	return (val);
}

static void				clean_mem(char *str)
{
	if (str)
	{
		memset(str, '\0', strlen(str));
		free(str);
	}
}
