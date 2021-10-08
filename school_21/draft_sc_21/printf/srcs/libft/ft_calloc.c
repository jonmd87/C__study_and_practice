/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:28:49 by lbardly           #+#    #+#             */
/*   Updated: 2020/07/29 22:41:05 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pnt;

	pnt = NULL;
	pnt = (void*)malloc(count * size);
	if (pnt)
		ft_bzero(pnt, count * size);
	return (pnt);
}
