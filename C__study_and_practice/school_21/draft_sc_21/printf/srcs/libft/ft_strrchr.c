/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:51:35 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/10 15:45:00 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*pnt;

	pnt = NULL;
	if (c >= 0)
	{
		while (*s != '\0')
		{
			if (*s == c)
				pnt = (char *)s;
			s++;
		}
		if (*s == '\0' && *s == c)
			pnt = (char*)s;
	}
	return (pnt);
}
