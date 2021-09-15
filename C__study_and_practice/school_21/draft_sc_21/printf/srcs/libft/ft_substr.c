/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:39:08 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/05 22:25:50 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt;
	char	*str;
	size_t	s_len;

	pnt = NULL;
	str = NULL;
	if (!s)
		return (pnt);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char*)ft_calloc(1, sizeof(char)));
	if ((pnt = (char*)ft_calloc(sizeof(char), (len + 1))))
	{
		str = (char*)s + start;
		ft_strlcpy(pnt, str, len + 1);
	}
	return (pnt);
}
