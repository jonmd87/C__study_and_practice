/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:25:23 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 10:44:05 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char		*correction(char *str, char spec)
{
	char	*corr_str;

	corr_str = str;
	if (spec == 'X')
		while (*str)
		{
			*str = ft_toupper(*str);
			str++;
		}
	else if (spec == 'p')
	{
		corr_str = ft_strjoin("0x", str);
		free(str);
		str = NULL;
	}
	return (corr_str);
}

int			check_res(t_arg *list)
{
	if (list->accur == 0 && list->point == 1 && (ft_atoi(list->str)) == 0)
		return (1);
	else
		return (0);
}

void		setup_flags(t_arg *list)
{
	if (list->plus > 0 && list->space > 0)
		list->space = 0;
	if (list->zero > 0 && list->sign < 1 && list->accur < 0)
		list->filler = '0';
	else
		list->filler = ' ';
	if (list->spec == 'p')
		list->filler = ' ';
}

void		clear_memory(char **str)
{
	if (*str)
	{
		ft_bzero(*str, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
}
