/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:06:45 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/25 13:58:03 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pnt;
	size_t	ind;

	pnt = NULL;
	ind = 0;
	if (!s || !f)
		return (pnt);
	if ((pnt = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		while (s[ind])
		{
			pnt[ind] = f(ind, s[ind]);
			ind++;
		}
		pnt[ind] = '\0';
	}
	return (pnt);
}
