/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:45:45 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/27 12:56:12 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_s)
{
	size_t	ind;

	ind = 0;
	if (!dst || !src)
		return (0);
	else if (dst_s > 0)
	{
		while (ind < dst_s - 1 && src[ind])
		{
			dst[ind] = src[ind];
			ind++;
		}
		dst[ind] = '\0';
	}
	return (ft_strlen(src));
}
