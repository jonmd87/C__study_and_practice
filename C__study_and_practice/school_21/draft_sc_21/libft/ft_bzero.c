/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:41:54 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/24 17:24:00 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
