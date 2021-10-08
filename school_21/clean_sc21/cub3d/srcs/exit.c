/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:15:24 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/28 19:13:52 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		clean_arr(char **str)
{
	size_t	size;
	size_t	ind;

	size = 0;
	ind = 0;
	while (str[size])
		size++;
	while (ind != size)
	{
		clean_mem(&str[ind]);
		ind++;
	}
	clean_mem(str);
}

void		clean_struct(t_info *file)
{
	clean_mem(&file->no->path);
	clean_mem(&file->so->path);
	clean_mem(&file->we->path);
	clean_mem(&file->ea->path);
	clean_mem(&file->s->path);
	clean_arr(file->map->map);
	init_struct(file);
}

void		ft_quit(int flag, char *mess)
{
	if (flag == 1)
	{
		ft_putstr_fd("ERROR:", 1);
		ft_putendl_fd(mess, 1);
	}
	else
		ft_putendl_fd(mess, 1);
	exit(flag);
}
