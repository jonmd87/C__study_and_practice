/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/02/17 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write a function that cycles the bits of an unsigned int value
** by the specified number of positions to the left.
** For example, the function rotate_l (x,4) moves the bits of the value x four
** positions to the left, while the bits lost on the left are reproduced
** on the right side of the combination. In other words,
** the displaced high bit is placed in the position of the low bit.
** Test the function in a program.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <limits.h>
 
#define LEN sizeof(unsigned int) * CHAR_BIT

static int				get_data(unsigned int *num, unsigned int *rot);
static int				get_number(unsigned int *n, ssize_t min, ssize_t max);
static unsigned int		rotate(unsigned int num, unsigned int rot);
static char				*itobin(unsigned int num, int ind);
static void				clean_mem(char *str);

int						main(void)
{
	unsigned int		num;
	unsigned int		rot;
	unsigned int		res;
	char				*str;

	while (get_data(&num, &rot) > 0)
	{
		res = rotate(num, rot);
		str = itobin(num, LEN);
		printf("I need to rotate %i bits in this number:\n", rot);
		printf("[%-10u]--BINARY-->[%s] |<--original data\n", num, str);
		clean_mem(str);
		str = itobin(res, LEN);
		printf("[%-10u]--BINARY-->[%s] |<--rotated  data\n", res, str);
		clean_mem(str);
	}
	puts("!!!GOOD BYE!!!");
	return (0);
}
static int				get_data(unsigned int *num, unsigned int *rot)
{
	int					res;

	printf("Enter a (unsgned int)number.\n");
	printf("-= number in limits [%i] and [%u] (inclusively)=-\n", 0, UINT_MAX);
	res = get_number(&(*num), 0, UINT_MAX);
	if (res == 0)
		return (0);
	printf("Now enter the quantity of bits to sheet.\n");
	printf("-= number in limits [%i] and [%lu] (inclusively)=-\n", 0, LEN);
	res = get_number(&(*rot), 0, LEN);
	if (res == 0)
		return (0);
	return (1);
}

static int				get_number(unsigned int *n,	ssize_t min, ssize_t max)
{
	ssize_t				temp;

	while (1)
	{
		if ((scanf("%lu", &temp)) != 1)
		{
			if (toupper(getchar()) == 'Q')
				return (0);
		}
		else if (temp >= min && temp <= max)
		{
			*n = (unsigned int)temp;
			return (1);
		}
		printf("ERROR: ------>> wrong input data\nREMEMBER:____!!!!  ");
		printf("-= number in limits [%lu] and [%lu] (inclusively)=-\n", min, max);
		while (getchar() != '\n');
	}
	return (0);
}

static unsigned int		rotate(unsigned int num, unsigned int rot)
{
	unsigned int		mask;
	unsigned int		res;

	res = 0;
	mask = num >> (LEN - 2);
	num <<= rot;
	res = num | mask;
	return (res);
}

static char			*itobin(unsigned int num, int ind)
{
	char			*str;

	if ((str = (char*)calloc(sizeof(char), LEN + 1)))
	{
		memset(str, '0', LEN);
		while (num != 0)
		{
			str[--ind] = num % 2 + '0';
			num /= 2;
		}
	}
	return (str);
}

static void			clean_mem(char *str)
{
	if (str)
	{
		memset(str, '\0', strlen(str));
		free(str);
	}
}
