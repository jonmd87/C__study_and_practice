/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distribution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:33:46 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 11:07:21 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int		make_diff(t_arg *list)
{
	int			diff;
	int			ch;
	int			num;

	ch = 0;
	diff = 0;
	num = 0;
	if (list->spec == '%')
	{
		list->ch = '%';
		num = 1;
	}
	if (list->width < 1)
		list->width = 1;
	diff = list->width - num;
	return (diff);
}

int				empty(t_arg *list)
{
	int			val;
	int			diff;

	val = 0;
	diff = 0;
	diff = make_diff(list);
	if (list->zero > 0 && list->sign < 1)
		list->filler = '0';
	else
		list->filler = ' ';
	if (list->sign == 1)
		if (list->ch > 0)
			val += print_chars(list->ch, 1);
	if (diff > val)
		val += print_chars(list->filler, diff);
	if (val < list->width)
		val += print_chars(list->ch, 1);
	return (val);
}

int				distribution(t_arg *list)
{
	int			val;

	val = 0;
	if (list->spec == 'u' || list->spec == 'x' || list->spec == 'X')
		val = show_unsig(list);
	else if (list->spec == 'i' || list->spec == 'd')
		val = show_integers(list);
	else if (list->spec == 'p')
		val = show_adres(list);
	else if (list->spec == 's')
		val = show_strings(list);
	else if (list->spec == 'c')
		val = show_chars(list);
	else
		val = empty(list);
	if (list->str)
		clear_memory(&list->str);
	initial(list);
	free(list);
	return (val);
}
