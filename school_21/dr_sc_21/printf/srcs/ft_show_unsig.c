/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_unsig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:55:30 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 11:54:47 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int				check_un_res(t_arg *list)
{
	if (list->accur == 0 && list->point == 1 && ((unsigned int)list->raw) == 0)
		return (1);
	return (0);
}

static int				make_differnt(t_arg *list)
{
	int					diff;

	diff = 0;
	if (list->len > list->accur)
		list->accur = list->len;
	if (list->width < list->accur)
		list->width = list->accur;
	if (list->len > list->accur)
		diff = list->width - list->len;
	else
		diff = list->width - list->accur;
	return (diff);
}

int						output_un(t_arg *list)
{
	int					val;
	int					diff;

	val = 0;
	diff = 0;
	list->len = ft_strlen(list->str);
	if ((check_un_res(list)))
		list->len = 0;
	setup_flags(list);
	if (list->sign < 1)
	{
		diff = make_differnt(list);
		if (list->width > list->accur)
			val += print_chars(list->filler, diff);
	}
	if (list->accur > list->len)
		val += print_chars('0', list->accur - list->len);
	if (!(check_un_res(list)))
		val += putstring(list->str, list->len);
	if (val < list->width)
		val += print_chars(list->filler, list->width - val);
	return (val);
}

static int				prepare(t_arg *list)
{
	int					val;

	val = 0;
	if (list->str == NULL)
		return (-1);
	list->str = correction(list->str, list->spec);
	val += output_un(list);
	return (val);
}

int						show_unsig(t_arg *list)
{
	unsigned long int	num;
	unsigned long int	res;
	unsigned long int	div;
	int					ind;
	int					val;

	num = (unsigned int)list->raw;
	ind = get_cell(num, &div, list->spec);
	val = 0;
	if ((list->str = (char*)ft_calloc(ind + 1, sizeof(char))))
	{
		if (ind == 0)
			list->str[0] = '0';
		while (ind--)
		{
			res = num % div;
			if (res < 16 && res > 9)
				list->str[ind] = 'a' + (res - 10);
			else
				list->str[ind] = '0' + res;
			num /= div;
		}
	}
	val += prepare(list);
	return (val);
}
