/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:55:19 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/03 06:58:05 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		clean_arr(char **str)
{
	int		ind;

	ind = 0;
	while (str[ind])
	{
		clean_str(str[ind]);
		ind++;
	}
	str = NULL;
}

void		clean_str(char *str)
{
	ft_bzero(str, ft_strlen(str));
	free(str);
	str = NULL;
}

void		ft_quit(int code, const char *message)
{
	if (code == 1)
	{
		ft_putstr_fd("ERROR:>>>>>>", 1);
		ft_putendl_fd((char*)message, 1);
		exit(1);
	}
	else if (code == 0)
	{
		ft_putstr_fd(")))))succes ", 1);
		ft_putendl_fd((char*)message, 1);
		exit(1);
	}
}
