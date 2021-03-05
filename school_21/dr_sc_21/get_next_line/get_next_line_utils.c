/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 10:04:54 by lbardly           #+#    #+#             */
/*   Updated: 2020/07/16 12:37:58 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (c >= 0)
	{
		while (*s)
		{
			if (*s == c)
				return ((char*)s);
			s++;
		}
		if (*s == '\0' && *s == c)
			return ((char*)s);
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (str[num])
		num++;
	return (num);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnt;
	size_t	ind;
	size_t	len;

	pnt = NULL;
	ind = 0;
	if (!s1)
		return (pnt);
	if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((pnt = (char*)ft_calloc(sizeof(char*), (len + 1))))
	{
		while (*s1 && ind != len)
			pnt[ind++] = *s1++;
		while (*s2 && ind != len)
			pnt[ind++] = *s2++;
		pnt[ind] = '\0';
	}
	return (pnt);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pnt;
	size_t			ind;

	pnt = (unsigned char*)s;
	ind = 0;
	while (ind != n)
	{
		pnt[ind] = '\0';
		ind++;
	}
}
