/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 12:42:16 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/27 10:45:30 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			ind;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	ind = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (ind < n)
	{
		dest[ind] = source[ind];
		ind++;
	}
	return (dest);
}
