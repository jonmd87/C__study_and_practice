/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:45:03 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/24 16:09:28 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stc, const char *pin, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (*pin == '\0')
		return ((char*)stc);
	while (stc[i] && i < len)
	{
		x = 0;
		while (pin[x] && stc[i + x] == pin[x] && i + x < len && stc[i + x])
			x++;
		if (pin[x] == '\0')
			return ((char*)&stc[i]);
		i++;
	}
	return (NULL);
}
