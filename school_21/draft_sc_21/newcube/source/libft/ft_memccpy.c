/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:32:20 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/28 21:47:29 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destin;
	unsigned char	*source;
	unsigned char	ch;

	destin = (unsigned char*)dst;
	source = (unsigned char*)src;
	ch = (unsigned char)c;
	while (n--)
	{
		*destin = *source;
		destin++;
		source++;
		if (*(destin - 1) == ch)
			return (destin);
	}
	return (NULL);
}
