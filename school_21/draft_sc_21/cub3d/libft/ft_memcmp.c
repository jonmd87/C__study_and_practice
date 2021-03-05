/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:02:32 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/10 15:41:47 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*first;
	unsigned char		*second;
	size_t				ind;

	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	ind = 0;
	while (ind < n)
	{
		if (first[ind] != second[ind])
			return (first[ind] - second[ind]);
		ind++;
	}
	return (0);
}
