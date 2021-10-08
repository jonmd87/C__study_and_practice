/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:48:03 by lbardly           #+#    #+#             */
/*   Updated: 2020/09/05 17:40:20 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new;

	new = NULL;
	if ((new = (t_list*)ft_calloc(sizeof(t_list), 1)))
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
