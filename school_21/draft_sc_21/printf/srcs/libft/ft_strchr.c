/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:54:26 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/10 15:43:57 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
