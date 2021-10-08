/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_integ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:58:48 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 11:43:41 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			make_ch(t_arg *list)
{
	char		*temp;

	temp = NULL;
	if (list->str[0] == '-')
	{
		list->ch = '-';
		list->len = ft_strlen(list->str);
		temp = ft_substr(list->str, 1, list->len - 1);
		clear_memory(&list->str);
		list->str = temp;
		list->len = ft_strlen(list->str);
		temp = NULL;
	}
	else if (list->plus > 0 && list->str[0] != '-')
		list->ch = '+';
	else if (list->space > 0 && list->plus < 1 && list->str[0] != '-')
		list->ch = ' ';
}

static int		make_diff(t_arg *list)
{
	int			diff;
	int			ch;

	diff = 0;
	ch = 0;
	if (list->ch > 0)
		ch = 1;
	if (list->width > list->accur && list->accur > list->len)
		diff = list->width - list->accur - ch;
	else
		diff = list->width - list->len - ch;
	return (diff);
}

static int		output_i(t_arg *list)
{
	int			val;
	int			diff;

	diff = 0;
	val = 0;
	if (list->sign < 1)
	{
		if (list->filler == '0' && list->ch > 0)
			val += print_chars(list->ch, 1);
		diff = make_diff(list);
		if (val > 0)
			list->ch = 0;
		if (list->width > list->accur)
			val += print_chars(list->filler, diff);
	}
	if (list->ch > 0)
		val += print_chars(list->ch, 1);
	if (list->accur > list->len)
		val += print_chars('0', (list->accur - list->len));
	if (!(check_res(list)))
		val += putstring(list->str, list->len);
	if (val < list->width)
		val += print_chars(list->filler, (list->width - val));
	return (val);
}

int				show_integers(t_arg *list)
{
	int			val;

	val = 0;
	list->str = ft_itoa((int)list->raw);
	if (list->str == NULL)
		return (-1);
	make_ch(list);
	setup_flags(list);
	list->len = ft_strlen(list->str);
	if ((check_res(list)))
		list->len = 0;
	val += output_i(list);
	return (val);
}
