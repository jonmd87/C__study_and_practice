/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_adres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:00:05 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 11:47:50 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

int						show_adres(t_arg *list)
{
	unsigned long int	num;
	unsigned long int	res;
	unsigned long int	div;
	int					ind;
	int					val;

	num = (unsigned long int)list->raw;
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
