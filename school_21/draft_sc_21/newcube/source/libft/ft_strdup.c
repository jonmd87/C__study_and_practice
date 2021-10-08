/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:05:13 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/24 16:51:43 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pnt;
	size_t	len;

	pnt = NULL;
	len = ft_strlen(s1);
	if ((pnt = (char*)malloc(sizeof(char) * (len + 1))))
		ft_strlcpy(pnt, s1, len + 1);
	return (pnt);
}
