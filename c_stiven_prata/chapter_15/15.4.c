/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/02/13 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write the function that takes two numbers (int):
** first number is an integer number
** second number is the bit position
** If bit in this position is [1] function return [1]
** If bit in this position is [0] function return [0]
** Test the function in a program.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

#define LEN sizeof(int) * CHAR_BIT
#define LEN1 LEN + LEN / 4 

static int				get_data(int	*num1, int *num2);
static int				get_number(int *num, int min, int max, char *message);
static char				*itobin(int num, unsigned int ind);
static void				print_bin(const char *str);
static void				clean_mem(char *str);

int						main(void)
{
	char				*str;
	int					num1;
	int					num2;
	int					val;

	val = 0;
	while (get_data(&num1, &num2) == 0)
	{
		str = itobin(num1, (unsigned int)LEN);
		printf("Number[%i] position[%i]\n", num1, num2);
		print_bin(str);
		val = LEN1 - (num2 + num2 / 4 - (num2 % 4 ? 0 : 1));
		printf("\n%*c\n", val, str[LEN - num2]);
		clean_mem(str);
	}
	puts("Good Buy");
	return (0);
}

static int				get_data(int	*num1, int *num2)
{
	int					res;

	res = 0;
	printf("Enter integer number, whithin limits %i and %i\n", 
												INT_MAX, INT_MIN);
	res = get_number(&(*num1), INT_MIN, INT_MAX, "Enter integer number,");
	if (res == 0)
		return (1);
	while (getchar() != '\n');
	printf("Now enter bit position (int has 32 bits), ");
	printf("more than %i and less then %lu\n", 0, LEN + 1);
	res = get_number(&(*num2), 0, (int)(LEN + 1),
								"Enter bit position (int has 32 bits),");
	if (res == 0)
		return (1);
	return (0);
}

static int				get_number(int *num, int min, int max, char *message)
{
	ssize_t				temp;

	while (1)
	{
		if (scanf("%lu", &temp) != 1)
		{
			if (toupper(getchar()) == 'Q')
				return (0);
		}
		else if (temp < min || temp > max)
		{
			printf("%s whihin limits %i and %i\n", message, min, max);
			continue ;
		}
		else
			break ;
		puts("wrong data");
		while (getchar() != '\n');
	}
	*num = temp;
	return (1);
}

static char				*itobin(int num, unsigned int ind)
{
	char 				*str;

	if ((str = (char*)calloc(sizeof(char), ind + 1)))
	{
		memset(str, '0', ind);
		while (num != 0)
		{
			str[--ind] = (num % 2) + '0';
			num /= 2;
		}
	}
	return (str);
}

static void				print_bin(const char *str)
{
	unsigned int		ind;

	ind = 0;
	while (str[ind])
	{
		printf("%c", str[ind]);		
		ind++;
		if (ind < LEN &&(ind % 4) == 0)
			printf("%c", ' ');		
	}
}

static void				clean_mem(char *str)
{
	if (str)
	{
		memset(str, '\0', LEN);
		free(str);
	}
}
