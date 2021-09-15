/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:02:23 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 11:52:35 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int		check_string(t_arg *list)
{
	if (list->str == NULL)
		list->str = ft_substr("(null)", 0, ft_strlen("(null)"));
	else
		list->str = ft_strdup((char*)list->raw);
	if (list->str == NULL)
		return (-1);
	list->len = ft_strlen(list->str);
	if (list->accur < 0)
		list->accur = list->len;
	if (list->accur > list->len)
		list->accur = list->len;
	if (list->width < list->accur)
		list->width = list->accur;
	return (0);
}

int				show_strings(t_arg *list)
{
	int			val;

	val = 0;
	list->str = ((char*)list->raw);
	if ((check_string(list)) == -1)
		return (-1);
	if (list->sign == 0)
		val += print_chars(' ', list->width - list->accur);
	val += putstring(list->str, list->accur);
	if (val < list->width)
		val += print_chars(' ', list->width - list->accur);
	return (val);
}
