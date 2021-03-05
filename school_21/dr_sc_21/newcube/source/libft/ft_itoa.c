/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:58:35 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/25 14:11:16 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_cell(long int n, long int *flag)
{
	long int	i;

	i = 0;
	if (n < 0)
		*flag = -1;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	num;
	long int	flag;
	char		*pnt;
	int			ind;

	num = (long int)n;
	flag = 1;
	pnt = NULL;
	ind = get_cell(num, &flag);
	if ((pnt = (char*)ft_calloc(ind + 1, sizeof(char))))
	{
		num *= flag;
		while (ind--)
		{
			pnt[ind] = (num % 10) + '0';
			num = num / 10;
		}
		if (flag == -1)
			pnt[0] = '-';
	}
	return (pnt);
}
