/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:21:56 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/27 10:56:48 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pnt;
	size_t			ind;

	pnt = (unsigned char *)b;
	ind = 0;
	while (ind < len)
	{
		pnt[ind] = (unsigned char)c;
		ind++;
	}
	return ((void *)b);
}
