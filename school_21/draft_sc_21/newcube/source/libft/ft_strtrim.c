/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 08:19:59 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/27 12:58:25 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pnt;
	size_t	len;
	size_t	ind;

	pnt = NULL;
	len = 0;
	ind = 0;
	if (!s1)
		return (pnt);
	while (s1[ind] && ft_strchr(set, s1[ind]))
		ind++;
	len = ft_strlen(s1);
	while (len && len > ind && ft_strchr(set, s1[len - 1]))
		len--;
	pnt = ft_substr((char*)s1 + ind, 0, len - ind);
	return (pnt);
}
