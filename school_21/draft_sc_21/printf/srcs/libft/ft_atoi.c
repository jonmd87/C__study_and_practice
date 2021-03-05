/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:53:31 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/22 07:44:33 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	flag;
	long int	val;

	flag = 1;
	val = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	if (ft_isdigit(*str))
		while ((*str) && ft_isdigit(*str))
		{
			val = (val * 10) + (*str - '0');
			str++;
		}
	return ((int)(val * flag));
}
