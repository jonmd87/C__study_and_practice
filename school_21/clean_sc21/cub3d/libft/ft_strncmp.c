/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 08:19:54 by lbardly           #+#    #+#             */
/*   Updated: 2020/09/07 20:43:38 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 														///////////////
#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			ind;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	ind = 0;
	while ((s1[ind] || s2[ind]) && ind < n)
	{
		if (s1[ind] != s2[ind])
			return (s1[ind] - s2[ind]);
		ind++;
	}
	return (0);
}
