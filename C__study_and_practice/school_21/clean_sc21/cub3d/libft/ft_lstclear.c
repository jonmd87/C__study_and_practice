/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:08:10 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/15 20:13:15 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;

	temp = NULL;
	list = NULL;
	if (lst == NULL || *lst == NULL)
		return ;
	list = *lst;
	while (list)
	{
		temp = list;
		list = list->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
