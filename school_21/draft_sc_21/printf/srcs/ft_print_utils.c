/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:06:31 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/05 22:09:23 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		print_chars(const char ch, const int val)
{
	int		num;

	num = 0;
	while (num < val)
	{
		ft_putchar_fd(ch, 1);
		num++;
	}
	return (num);
}

int		putstring(const char *str, int lenth)
{
	int		val;
	int		len;

	val = 0;
	len = ft_strlen(str);
	while (val < lenth)
		ft_putchar_fd(str[val++], 1);
	return (val);
}
