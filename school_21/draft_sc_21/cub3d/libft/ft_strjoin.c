/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 08:09:14 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/25 14:00:31 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if ((pnt = (char*)malloc(sizeof(char*) * (len + 1))))
	{
		while (*s1 && ind != len)
			pnt[ind++] = *s1++;
		while (*s2 && ind != len)
			pnt[ind++] = *s2++;
		pnt[ind] = '\0';
	}
	return (pnt);
}
