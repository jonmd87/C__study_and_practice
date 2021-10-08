/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:01:09 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/15 20:30:43 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	temp = NULL;
	if (lst)
	{
		temp = lst;
		lst = lst->next;
		del(temp->content);
		free(temp);
		temp = NULL;
	}
}
