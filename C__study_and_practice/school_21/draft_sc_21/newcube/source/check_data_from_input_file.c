/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_from_input_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:06:16 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/10 07:30:07 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			check_resolution(t_info *f)
{
	int			wid;
	int			hei;

	wid = 0;
	hei = 0;
	if (f->wid < 1 || f->hei < 1)
		ft_quit(FAIL, BAD_RES);
	if (f->win != NULL)
	{
		mlx_get_screen_size(f->win->mlx, &wid, &hei);
		if (f->wid > wid)
			f->wid = wid;
		if (f->hei > hei)
			f->hei = hei;
	}
}

int				check_allowed_char(const char *patt, const char *str)
{
	size_t		ind;
	size_t		check;

	ind = 0;
	check = ft_strlen(str);
	if (!str)
		return (-1);
	while (*str && ft_strchr(patt, *str))
	{
		str++;
		ind++;
	}
	if (ind == check)
		return (1);
	return (-1);
}

int				check_empty_line(const char *str)
{
	while (*str && *str != '\n')
	{
		if (ft_isalnum(*str))
			return (1);
		str++;
	}
	return (0);
}

static void		check_valid_path(t_texture *tex, char *mess)
{
	int			fd;

	fd = -1;
	if (!tex)
		ft_quit(FAIL, mess);
}

void			check_cup(t_info *f)
{
	check_valid_path(f->no, NO_TEX_NO);
	check_valid_path(f->so, NO_TEX_SO);
	check_valid_path(f->we, NO_TEX_WE);
	check_valid_path(f->ea, NO_TEX_EA);
	check_valid_path(f->spirit, NO_TEX_SPIRIT);
}
