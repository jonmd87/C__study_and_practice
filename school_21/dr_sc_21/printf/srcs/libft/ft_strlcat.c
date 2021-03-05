/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 10:26:03 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/24 22:15:18 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_s)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len < dst_s)
	{
		ft_strlcpy(&dst[dst_len], src, (dst_s - dst_len));
		return (dst_len + src_len);
	}
	return (dst_s + src_len);
}
