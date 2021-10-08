/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:50:41 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/05 22:48:37 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			show_chars(t_arg *list)
{
	unsigned char	ch;
	int				val;
	int				res;

	val = 0;
	res = 1;
	ch = (unsigned char)list->raw;
	if (list->width < 1)
		list->width = 1;
	if (list->sign == 1)
		val += print_chars(ch, 1);
	if (val < list->width)
		val += print_chars(' ', list->width - 1);
	if (val < list->width)
		val += print_chars(ch, 1);
	return (val);
}
